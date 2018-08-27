#include <unistd.h>

#include <cstring>
#include <string>

#include "parameters.hpp"

using std::string;

namespace uc {

const string parameters::COMMAND_NAME("unicodeConverter");

parameters::parameters(int argc, char *argv[]) {
  valid = true;
  if (argc <= 1) {
    valid = false;
    return;
  }

  string program_name(argv[0]);
  if (program_name != COMMAND_NAME) {
    valid = false;
    return;
  }

  type = NO_TYPE;
  parse_arguments(argc, argv);

  validate();
}

void parameters::parse_arguments(int argc, char *argv[]) {
  int option = -1;
  while (optind < argc) {
    option = getopt(argc, argv, "t:");
    if (option != -1) {
      switch (option) {
      case 't':
        process_type(optarg);
        break;
      case '?':
        valid = false;
        break;
      }
    } else {
        this->text = string(argv[argc - 1]);
        break;
    }
  }
}

void parameters::process_type(string type) {
  if (type == "atech") {
    this->type = ATECH;
  }
}

void parameters::validate() {
    if (text.empty()) {
        valid = false;
    } else if (type == NO_TYPE) {
        valid = false;
    }
}

parameters::~parameters() {}

bool parameters::is_valid() const { return valid; }

string parameters::get_text() const { return text; }

type parameters::get_type() const { return type; }
}
