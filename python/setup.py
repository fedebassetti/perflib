import os
import sys

from setuptools import setup, find_packages, Extension

# this_file = os.path.dirname(__file__)

module = Extension('perflib',
                   sources=['perflib/perflib.cc'],
                       define_macros=[('MAJOR_VERSION', '0'),('MINOR_VERSION', '1')],
                       include_dirs=['../src/'],
                       library_dirs=['../src/'],
                       libraries=[],
                       extra_compile_args=['-std=c++14', '-Wall', '-Wextra'],
                       extra_link_args=['-lperf']
                   )

setup(
    name='perflib',
    version='0.1',
    description='',
    long_description='',
    url='',
    author='John R. Emmons',
    author_email='jemmons@cs.stanford.edu',
    install_requires=[],
    setup_requires=[],
    packages=find_packages(exclude=['build']),
    ext_modules=[module]
)
