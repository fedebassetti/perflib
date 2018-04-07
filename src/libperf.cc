#include "libperf.hh"

#include <assert.h>
#include <fcntl.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stropts.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include <cstdint>
#include <vector>
#include <iostream>
#include <stdexcept>

const char* libperf::version_ = "0.1";

libperf::libperf_counter_ libperf::get_counter_by_name(std::string counter_name) {

    libperf::libperf_counter_ counter{counter_name};
    
    bool counter_exists = false;
    for(size_t i = 0; i < libperf::num_available_counters_; i++) {
        if( counter_name.compare(counters_[i].name) == 0 ){
            counter = libperf::counters_[i];
            counter_exists = true;
            break;
        }
    }
    
    if(not counter_exists){
        throw std::runtime_error(counter_name + " does not name a defined perf counter.");
    }

    return counter;
}

bool libperf::is_counter_available(std::string counter_name) {

    libperf::libperf_counter_ counter = libperf::get_counter_by_name(counter_name);
    
    counter.attributes.size = sizeof(perf_event_attr);
    counter.attributes.inherit = 1;
    counter.attributes.disabled = 1;
    counter.attributes.enable_on_exec = 0;
    
    pid_t pid = syscall(SYS_gettid);
    int cpu = -1;
    
    libperf::FDGuard fdg{syscall(__NR_perf_event_open,
                                 &counter.attributes, pid, cpu,
                                 -1, 0)
    };
    
    if(fdg.fd < 0){
        return false;
    }
    return true;
}


std::vector<std::string> libperf::get_counters_available(void) {

    std::vector<std::string> counters{};
    for(size_t i = 0; i < libperf::num_available_counters_; i++){
        
        std::string name = libperf::counters_[i].name;
        if(libperf::is_counter_available(name)) {
            counters[i] = name;
        }
    }

    return counters;
}


libperf::PerfCounter::PerfCounter(std::string counter_name) :
    counter_(counter_name),
    name_(counter_.name)
{
    
    if(not libperf::is_counter_available(counter_name) ){
        throw std::runtime_error("A performance counter for " + counter_name + " could not be created.");
    }
    
    counter_ = libperf::get_counter_by_name(counter_name);
    
    counter_.attributes.size = sizeof(perf_event_attr);
    counter_.attributes.inherit = 1;
    counter_.attributes.disabled = 1;
    counter_.attributes.enable_on_exec = 0;
    
    {
        pid_t pid = syscall(SYS_gettid);
        int cpu = -1;
        
        fd_ = syscall(__NR_perf_event_open,
                      &counter_.attributes, pid, cpu,
                      -1, 0);
    }        
}

libperf::PerfCounter::~PerfCounter(void) {
    close(fd_);
}

void libperf::PerfCounter::start(void) {
    
    int ret = ioctl(fd_, PERF_EVENT_IOC_ENABLE);
    if(ret < 0){
        throw std::runtime_error("Failed to start " + name_ + " counter.");
    }        
}

void libperf::PerfCounter::stop(void) {

    int ret =  ioctl(fd_, PERF_EVENT_IOC_DISABLE);
    if(ret < 0){
        throw std::runtime_error("Failed to stop " + counter_.name + " counter.");
    }        
}

void libperf::PerfCounter::reset(void) {}

uint64_t libperf::PerfCounter::getval(void) {

    uint64_t value;
    
    int bytes_read = read(fd_, &value, sizeof(uint64_t));
    assert(bytes_read == sizeof(uint64_t));
    
    return value;
}
