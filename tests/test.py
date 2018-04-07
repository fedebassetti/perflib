import perflib
import numpy as np

print(perflib.__name__)
print(perflib.__doc__)
print(perflib.__version__)

print(perflib.get_available_counters())

vals = []
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

p.reset()

p.start()
p.stop()

print(p.getval())

