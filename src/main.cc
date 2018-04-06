
#include "libperf.hh"
#include <iostream>

int main(){

    //std::cout << libperf::is_counter_available("LIBPERF_COUNT_HW_INSTRUCTIONS") << std::endl;
    //std::cout << libperf::is_counter_available("LIBPERF_COUNT_HW_CACHE_L1D_STORES_MISSES") << std::endl;

    libperf::PerfCounter p("LIBPERF_COUNT_HW_INSTRUCTIONS");

    size_t u = 10;
    p.start();

    for(int i = 0; i < 1000000; i++){
        u = i*i;
    }
    
    p.stop();
    std::cerr << "LIBPERF_COUNT_HW_INSTRUCTIONS: " << p.getval() << "\n";
    
    return u;
}

