#pragma once

#include <cstdint>
#include <vector>

namespace libperf {

    enum libperf_counter {

            /* sw tracepoints */
            LIBPERF_COUNT_SW_CPU_CLOCK = 0,
            LIBPERF_COUNT_SW_TASK_CLOCK = 1,
            LIBPERF_COUNT_SW_CONTEXT_SWITCHES = 2,
            LIBPERF_COUNT_SW_CPU_MIGRATIONS = 3,
            LIBPERF_COUNT_SW_PAGE_FAULTS = 4,
            LIBPERF_COUNT_SW_PAGE_FAULTS_MIN = 5,
            LIBPERF_COUNT_SW_PAGE_FAULTS_MAJ = 6,

            /* hw counters */
            LIBPERF_COUNT_HW_CPU_CYCLES = 7,
            LIBPERF_COUNT_HW_INSTRUCTIONS = 8,
            LIBPERF_COUNT_HW_CACHE_REFERENCES = 9,
            LIBPERF_COUNT_HW_CACHE_MISSES = 10,
            LIBPERF_COUNT_HW_BRANCH_INSTRUCTIONS = 11,
            LIBPERF_COUNT_HW_BRANCH_MISSES = 12,
            LIBPERF_COUNT_HW_BUS_CYCLES = 13,

            /* cache counters */

            /* L1D - data cache */
            LIBPERF_COUNT_HW_CACHE_L1D_LOADS = 14,
            LIBPERF_COUNT_HW_CACHE_L1D_LOADS_MISSES = 15,
            LIBPERF_COUNT_HW_CACHE_L1D_STORES = 16,
            LIBPERF_COUNT_HW_CACHE_L1D_STORES_MISSES = 17,
            LIBPERF_COUNT_HW_CACHE_L1D_PREFETCHES = 18,

            /* L1I - instruction cache */
            LIBPERF_COUNT_HW_CACHE_L1I_LOADS = 19,
            LIBPERF_COUNT_HW_CACHE_L1I_LOADS_MISSES = 20,

            /* LL - last level cache */
            LIBPERF_COUNT_HW_CACHE_LL_LOADS = 21,
            LIBPERF_COUNT_HW_CACHE_LL_LOADS_MISSES = 22,
            LIBPERF_COUNT_HW_CACHE_LL_STORES  = 23,
            LIBPERF_COUNT_HW_CACHE_LL_STORES_MISSES = 24,

            /* DTLB - data translation lookaside buffer */
            LIBPERF_COUNT_HW_CACHE_DTLB_LOADS = 25,
            LIBPERF_COUNT_HW_CACHE_DTLB_LOADS_MISSES = 26,
            LIBPERF_COUNT_HW_CACHE_DTLB_STORES = 27,
            LIBPERF_COUNT_HW_CACHE_DTLB_STORES_MISSES = 28,

            /* ITLB - instructiont translation lookaside buffer */
            LIBPERF_COUNT_HW_CACHE_ITLB_LOADS = 29,
            LIBPERF_COUNT_HW_CACHE_ITLB_LOADS_MISSES = 30,

            /* BPU - branch prediction unit */
            LIBPERF_COUNT_HW_CACHE_BPU_LOADS = 31,
            LIBPERF_COUNT_HW_CACHE_BPU_LOADS_MISSES = 32,

            /* Special internally defined "counter" */
            /* this is the _only_ floating point value */
            LIBPERF_LIB_SW_WALL_TIME = 33
        };
    

     class PerfCounter {
     public:

         static std::vector<libperf::libperf_counter> get_counters_available(void);
         static bool is_counter_available(libperf::libperf_counter counter);

         PerfCounter(libperf::libperf_counter counter);
         ~PerfCounter(void);

         inline void start_counter(void);
         inline void stop_counter(void);

         void reset_counter(void);

         uint64_t read_counter(void);

     private:
         libperf_counter counter_;
     };

}
