#include "libperf.hh"

#include <cstdint>
#include <vector>

using namespace libperf;

std::vector<libperf_counter> get_counters_available(void) {

    return std::vector<libperf_counter>();
}

bool is_counter_available(libperf_counter counter) {

    return (counter == 1);
    
}
                                                         

PerfCounter::PerfCounter(libperf_counter counter) :
    counter_(counter) {

}

PerfCounter::~PerfCounter(void) {}

inline void start_counter(void) {}
inline void stop_counter(void) {}

void reset_counter(void) {}

uint64_t read_counter(void) {

    return 42;

}
