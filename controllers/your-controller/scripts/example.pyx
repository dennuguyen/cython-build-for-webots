# cython: language_level=3
# cython: c_string_type=unicode, c_string_encoding=utf8
# distutils: language=c++

import cython

cdef public void print_hello():
    print("Hello!")