import os
import sys

from setuptools import setup, find_packages, Extension

module = Extension('perflib',
                   sources=['perflib/perflib.cc'],
                       define_macros=[],
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
