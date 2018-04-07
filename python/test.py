import perflib

print(perflib.__name__)
print(perflib.__doc__)
print(perflib.__version__)

p = perflib.PerfCounter(counter_name="LIBPERF_COUNT_HW_INSTRUCTIONS")
p.start()
p.stop()

print(p.getval())

p.reset()

