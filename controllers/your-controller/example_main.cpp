#include <Python.h>

#include <memory>
#include <stdexcept>

#include "example.h"

auto main(int argc, char **argv) -> int {
    // Startup Python interpretter.
    if (PyImport_AppendInittab("example", PyInit_example) == -1) {
        throw std::runtime_error("Could not extend built-in modules table.");
    }
    Py_Initialize();

    // Import our example module into the Python interpretter.
    auto module = PyImport_ImportModule("example");
    if (module == nullptr) {
        PyErr_Print();
        throw std::runtime_error("Could not import example.");
    }

    // Execute function from Cython.
    print_hello();

    // End the Python interpretter.
    Py_Finalize();

    return 0;
}