#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace std;

class MyPybind11Test {
    public:
        static void tprint(string str);

        MyPybind11Test();

    private:
        py::module pyModule;
};
