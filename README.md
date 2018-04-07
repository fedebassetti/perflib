# perflib: a python library for accessing CPU performance counters on linux.

## Prerequisites

```bash
sudo apt-get install build-essential
```

## Installation

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

p = perflib.PerfCounter(counter_name='LIBPERF_COUNT_HW_INSTRUCTIONS')
p.start()

# do computation here

p.stop()

print('The number of instructions that were executed:', p.getval())

p.reset() # 
```
