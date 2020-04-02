# pybind11issue

This demonstrates an issue with pybind11 when embedding a broken python module.

How to build and demonstrate:

````
git clone --recurse-submodules https://github.com/felfert/pybind11issue.git
cd pybind11issue
cmake -B build .
cmake --build build
cd build
./pb11test
````
