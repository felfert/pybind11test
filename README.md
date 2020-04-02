# pybind11issue

This demonstrates an issue with pybind11 when embedding a broken python module.

How to build and demonstrate:

````
git clone --recurse-submodules https://github.com/felfert/pybind11issue.git
cd pybind11issue
cmake -B build .
cmake --build build
./build/pb11test
````
This produces the following output:

````
catched ModuleNotFoundError: No module named 'doesnotexist'

At:
  ./pb11testpy.py(1): <module>
  <frozen importlib._bootstrap>(219): _call_with_frames_removed
  <frozen importlib._bootstrap_external>(728): exec_module
  <frozen importlib._bootstrap>(677): _load_unlocked
  <frozen importlib._bootstrap>(967): _find_and_load_unlocked
  <frozen importlib._bootstrap>(983): _find_and_load

Segmentation fault (core dumped)
````

Running it in gdb shows the following backtrace:
````
#0  0x00007ffff7dda1d6 in new_threadstate () from /lib64/libpython3.7m.so.1.0
#1  0x00007ffff7cbb595 in PyGILState_Ensure.cold () from /lib64/libpython3.7m.so.1.0
#2  0x0000000000413f2d in pybind11::detail::get_internals()::gil_scoped_acquire_local::gil_scoped_acquire_local() ()
#3  0x00000000004148a1 in pybind11::detail::get_internals() ()
#4  0x000000000041ba3a in pybind11::gil_scoped_acquire::gil_scoped_acquire() ()
#5  0x000000000041bc6a in pybind11::error_already_set::~error_already_set() ()
#6  0x00007ffff7add903 in __gxx_exception_cleanup(_Unwind_Reason_Code, _Unwind_Exception*) () from /lib64/libstdc++.so.6
#7  0x0000000000410c5b in main ()
````

Tested on:
 * Fedora 31, gcc version 9.3.1 20200317 (Red Hat 9.3.1-1) (GCC), python3-3.7.6-2.fc31.x86_64


