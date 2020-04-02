cmake_minimum_required(VERSION 3.16)
project(pybind11test)
configure_file(pb11testpy.py pb11testpy.py COPYONLY)

set(PYBIND11_CPP_STANDARD -std=c++11)
add_subdirectory(pybind11)

pybind11_add_module(pb11testcc MyPybind11Test.cc)

add_executable(pb11test MyPybind11Test.cc MyPybind11Test.hh)
target_compile_options(pb11test PRIVATE -fvisibility=hidden -Wall)
target_link_libraries(pb11test PRIVATE pybind11::embed)
