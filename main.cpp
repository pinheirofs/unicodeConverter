#include <cstdlib>

#include "parameters.hpp"

using uc::parameters;

int main(int argc, char* argv[]) {
    parameters param(argc, argv);
    return EXIT_SUCCESS;
}
