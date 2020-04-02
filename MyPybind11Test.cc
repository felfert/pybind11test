#include "MyPybind11Test.hh"
#include <pybind11/embed.h>
#include <iostream>
#include <thread>
#include <chrono>

namespace py = pybind11;
using namespace std;

void MyPybind11Test::tprint(string str) {
    cout << "cc:" << str << endl;
}

MyPybind11Test::MyPybind11Test(int nthreads)
    : pyModule(py::module::import("pb11testpy"))
    , pyClass(pyModule.attr("EmbedTest")(nthreads))
    , pyStart(pyClass.attr("start"))
    , pyStop(pyClass.attr("stop"))
{ }

void MyPybind11Test::start() {
    try {
        pyStart();
    } catch (exception &e) {
        cerr << "start() catched " << e.what() << endl;
    }
}

void MyPybind11Test::stop() {
    try {
        pyStop();
    } catch (exception &e) {
        cerr << "stop() catched " << e.what() << endl;
    }
}

int main(int argc, const char **argv) {
    try {
        pybind11::scoped_interpreter guard;
        MyPybind11Test test(10);
        test.start();
        {
            py::gil_scoped_release gil_release;
            this_thread::sleep_for(chrono::seconds(10));
        }
        test.stop();
    } catch (exception &e) {
        cerr << "main() catched " << e.what() << endl;
    }
    return 0;
}
