#include <cstdlib>
#include <sstream>
#include <string>

#include "parameters.hpp"

using std::string;
using std::stringstream;

using uc::parameters;

int test_parameter_00(int argc, char *argv[]) {
  parameters param(argc, argv);
  if (!param.is_valid()) {
    return EXIT_FAILURE;
  }

  string text(argv[argc - 1]);
  if (param.get_text() != text) {
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int test_parameter_01(int argc, char *argv[]) {
  parameters param(argc, argv);
  if (!param.is_valid()) {
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}

int main(int argc, char *argv[]) {
  stringstream ss;
  ss << argv[1];

  int test_id;
  ss >> test_id;

  int return_value = 0;
  switch (test_id) {
  case 0:
    return_value = test_parameter_00(argc - 2, argv + 2);
    break;
  case 1:
    return_value = test_parameter_01(argc - 2, argv + 2);
    break;
  }

  return return_value;
}
