#include <inttypes.h> /* for PRIu64 definition */
#include <stdint.h>   /* for uint64_t */
#include <stdio.h>    /* for printf family */
#include <stdlib.h>   /* for EXIT_SUCCESS definition */

#include "libperf.h"  /* standard libperf include */

int main(int argc, char* argv[])
{
    fprintf(stderr, "initalizing\n");

    int x;
    int y;
    int z;

    struct libperf_data* pd = libperf_initialize(-1,-1); /* init lib */
    fprintf(stderr, "initalized!\n");
    libperf_enablecounter(pd, LIBPERF_COUNT_HW_INSTRUCTIONS);
    //libperf_enablecounter(pd, LIBPERF_COUNT_HW_CPU_CYCLES);
    /* enable HW counter */

    for(x = 0; x < 1000000; x++){
        y = x + 1;
        x = y;
    }    

    /* obtain counter value */
    libperf_disablecounter(pd, LIBPERF_COUNT_HW_INSTRUCTIONS);
    //libperf_disablecounter(pd, LIBPERF_COUNT_HW_CPU_CYCLES);
    /* disable HW counter */
    uint64_t counter = libperf_readcounter(pd, LIBPERF_COUNT_HW_INSTRUCTIONS);
    //uint64_t counter = libperf_readcounter(pd, LIBPERF_COUNT_HW_CPU_CYCLES);


    fprintf(stdout, "counter read: %"PRIu64"\n", counter-857); /* printout */

    FILE* log = libperf_getlogger(pd); /* get log file stream */
    fprintf(log, "custom log message\n"); /* print a custom log message */

    //libperf_finalize(pd, 0); /* log all counter values */

    return EXIT_SUCCESS; /* success exit value */
}
