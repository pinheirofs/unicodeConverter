#include <string>

#include "parameters.hpp"

using std::string;

namespace uc {

const string parameters::COMMAND_NAME("unicodeConveter");

parameters::parameters(const int argc, const char *argv[]) {
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
}

void
parameters::parse_arguments(const int argc, const char* argv[]) {

}

parameters::~parameters() { }

bool
parameters::is_valid() const {
    return valid;
}

string
parameters::get_text() const {
    return text;
}

}
