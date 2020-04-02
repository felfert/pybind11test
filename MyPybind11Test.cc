#include "MyPybind11Test.hh"
#include <pybind11/embed.h>
#include <iostream>

namespace py = pybind11;
using namespace std;

void MyPybind11Test::tprint(string str) {
    cout << str << endl;
}

MyPybind11Test::MyPybind11Test()
    : pyModule(py::module::import("pb11testpy"))
{ }


int main(int argc, const char **argv) {
    try {
        pybind11::scoped_interpreter guard;
        MyPybind11Test test;
    } catch (exception &e) {
        cerr << "catched " << e.what() << endl;
    }
    return 0;
}
