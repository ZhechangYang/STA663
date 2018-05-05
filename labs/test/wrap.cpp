<%
cfg['compiler_args'] = ['-std=c++11']
cfg['include_dirs'] = ['../../notebooks/eigen3']
setup_pybind11(cfg)
%>

#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include "funcs.hpp"

namespace py = pybind11;

using namespace pybind11::literals;

PYBIND11_PLUGIN(wrap) {
    py::module m("wrap", "pybind11 example plugin");
    m.def("gd", &gd, "Gradient descent fucntion.");
    m.def("logistic", &logistic, "Logistic fucntion.");
    return m.ptr();
}