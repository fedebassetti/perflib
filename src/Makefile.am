AM_CPPFLAGS = $(CXX14_FLAGS)
AM_CXXFLAGS = $(PICKY_CXXFLAGS) -fPIC

noinst_LIBRARIES = libperf.a

libperf_a_SOURCES = libperf.hh libperf.cc exception.hh

noinst_PROGRAMS = test
test_SOURCES = main.cc
test_LDADD = libperf.a
