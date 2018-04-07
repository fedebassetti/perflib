import perflib

print(perflib.__name__)
print(perflib.__doc__)
print(perflib.__version__)

print(perflib.get_available_counters())

p = perflib.PerfCounter(counter_name='LIBPERF_COUNT_HW_INSTRUCTIONS')
p.start()
p.stop()

print(p.getval())

p.reset()

p.start()
p.stop()

print(p.getval())

