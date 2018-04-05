#pragma once

#include <cstdint>
#include <vector>

class PerfCounter {
public:
    
    static std::vector<libperf::libperf_counter> get_counters_available(void);
    static bool is_counter_available(libperf_counter counter);
    
    PerfCounter(libperf::libperf_counter counter);
    ~PerfCounter(void);

    inline void start_counter(void);
    inline void stop_counter(void);

    void reset_counter(void);

    uint64_t read_counter(void);

private:
    
}
