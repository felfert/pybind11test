#include <pybind11/pybind11.h>

namespace py = pybind11;
using namespace std;

class MyPybind11Test {
    public:
        static void tprint(string str);

        MyPybind11Test(int nthreads);

        void start();
        void stop();

    private:
        py::module pyModule;
        py::object pyClass;
        py::function pyStart;
        py::function pyStop;
};

PYBIND11_MODULE(pb11testcc, m) {
    m.def("tprint", &MyPybind11Test::tprint, "print in c++");
}
