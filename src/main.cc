
#include "libperf.hh"
#include <iostream>

int main(){

    //std::cout << libperf::is_counter_available("LIBPERF_COUNT_HW_INSTRUCTIONS") << std::endl;
    //std::cout << libperf::is_counter_available("LIBPERF_COUNT_HW_CACHE_L1D_STORES_MISSES") << std::endl;

    libperf::PerfCounter p1("LIBPERF_COUNT_HW_INSTRUCTIONS");
    p1.start();
    p1.stop();
    std::cerr << "LIBPERF_COUNT_HW_INSTRUCTIONS1: " << p1.getval() << "\n";

    p1.reset();

    p1.start();
    p1.stop();
    std::cerr << "LIBPERF_COUNT_HW_INSTRUCTIONS1: " << p1.getval() << "\n";
    
    p1.reset();

    p1.start();
    int u = 0;
    for(int i = 0; i < 100000; i++){
        u = u + i;
    }
    p1.stop();
    std::cerr << "LIBPERF_COUNT_HW_INSTRUCTIONS1: " << p1.getval() << "\n";

    p1.reset();

    p1.start();
    p1.stop();
    std::cerr << "LIBPERF_COUNT_HW_INSTRUCTIONS1: " << p1.getval() << "\n";

    p1.reset();

    p1.start();
    p1.stop();
    std::cerr << "LIBPERF_COUNT_HW_INSTRUCTIONS1: " << p1.getval() << "\n";
    
    libperf::PerfCounter p2("LIBPERF_COUNT_HW_INSTRUCTIONS");
    p2.start();

    // for(int i = 0; i < 1000000; i++){
    //     u = i*i;
    // }
    
    p2.stop();
    std::cerr << "LIBPERF_COUNT_HW_INSTRUCTIONS2: " << p2.getval() << "\n";

    return u;
}

