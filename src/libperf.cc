#include "libperf.hh"

#include <cstdint>
#include <vector>


std::vector<libperf::libperf_counter> get_counters_available(void) {

    return std::vector<libperf::libperf_counter>();
}

bool is_counter_available(libperf_counter counter) {

    return true;
    
}
                                                         

PerfCounter(libperf::libperf_counter counter) {}
~PerfCounter(void) {}

inline void start_counter(void) {}
inline void stop_counter(void) {}

void reset_counter(void) {}

uint64_t read_counter(void) {

    return 42;

}
