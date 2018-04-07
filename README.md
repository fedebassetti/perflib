# perflib

**Description**: a python library for accessing CPU performance counters on linux.

## Prerequisites

```bash
sudo apt-get install build-essential
sudo apt-get install linux-tools-generic perf

```

## Installation from pip

```bash
pip install perflib
```

## Installation from source

```bash
./autogen.sh
./configure

make -j
make install
```

## Example

```python
import perflib

print(perflib.__name__)
print(perflib.__doc__)
print(perflib.__version__)

# print the available performance counters
print(perflib.get_available_counters())

# create a new performance counter object
# will record the performance for *this* process across all CPUs
p = perflib.PerfCounter(counter_name='LIBPERF_COUNT_HW_INSTRUCTIONS')

p.start()
# do computation here...
p.stop()

print('The number of instructions that were executed:', p.getval())

p.reset() # do this to *zero* out the counter for a fresh start

p.start()
# do computation here...
p.stop()
```

## Calibration

```python
import perflib
import numpy as np

p = perflib.PerfCounter(counter_name='LIBPERF_COUNT_HW_INSTRUCTIONS')

N = 10000
for _ in range(N):
    p.start()
    p.stop()
    vals.append(p.getval())
    p.reset()

vals = np.asarray(vals)

print('min', np.min(vals))
print('max', np.max(vals))
print('median', np.median(vals))
print('mean', np.mean(vals))
print('stdev', np.std(vals))

# prints ...
# min 1899
# max 19398
# median 1965
# mean 1983.2009
# stdev 269.0817
```

## Available counters

```bash
python
>>> import perflib
>>> counters = perflib.get_available_counters()
>>> print( '\n'.join(counters) )
LIBPERF_COUNT_SW_CPU_CLOCK
LIBPERF_COUNT_SW_TASK_CLOCK
LIBPERF_COUNT_SW_CONTEXT_SWITCHES
LIBPERF_COUNT_SW_CPU_MIGRATIONS
LIBPERF_COUNT_SW_PAGE_FAULTS
LIBPERF_COUNT_SW_PAGE_FAULTS_MIN
LIBPERF_COUNT_SW_PAGE_FAULTS_MAJ
LIBPERF_COUNT_HW_CPU_CYCLES
LIBPERF_COUNT_HW_INSTRUCTIONS
LIBPERF_COUNT_HW_CACHE_REFERENCES
LIBPERF_COUNT_HW_CACHE_MISSES
LIBPERF_COUNT_HW_BRANCH_INSTRUCTIONS
LIBPERF_COUNT_HW_BRANCH_MISSES
LIBPERF_COUNT_HW_BUS_CYCLES
LIBPERF_COUNT_HW_CACHE_L1D_LOADS
LIBPERF_COUNT_HW_CACHE_L1D_LOADS_MISSES
LIBPERF_COUNT_HW_CACHE_L1D_STORES
LIBPERF_COUNT_HW_CACHE_L1I_LOADS_MISSES
LIBPERF_COUNT_HW_CACHE_LL_LOADS
LIBPERF_COUNT_HW_CACHE_LL_LOADS_MISSES
LIBPERF_COUNT_HW_CACHE_LL_STORES
LIBPERF_COUNT_HW_CACHE_LL_STORES_MISSES
LIBPERF_COUNT_HW_CACHE_DTLB_LOADS
LIBPERF_COUNT_HW_CACHE_DTLB_LOADS_MISSES
LIBPERF_COUNT_HW_CACHE_DTLB_STORES
LIBPERF_COUNT_HW_CACHE_DTLB_STORES_MISSES
LIBPERF_COUNT_HW_CACHE_ITLB_LOADS
LIBPERF_COUNT_HW_CACHE_ITLB_LOADS_MISSES
LIBPERF_COUNT_HW_CACHE_BPU_LOADS
LIBPERF_COUNT_HW_CACHE_BPU_LOADS_MISSES
```
