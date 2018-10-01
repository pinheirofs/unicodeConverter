#include <cstdlib>
#include <sstream>
#include <string>

#include <text_converter.hpp>

using std::string;
using std::stringstream;

using uc::text_converter;

int test_converter_0(char** argv) {
    string format(argv[0]);
    string text(argv[1]);
    string text_unicode(argv[2]);

    text_converter converter;
    converter.set_text_original(text);
    converter.convert();

    string converted_text = converter.get_text_converted();
    if (converted_text != text_unicode) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        return EXIT_FAILURE;
    }

    stringstream ss;
    ss << argv[1];

    int return_value = 0;

    int test_index = 0;
    ss >> test_index;
    switch (test_index) {
    case 0:
        return_value = test_converter_0(argv + 2);
        break;
    default:
        return_value = EXIT_FAILURE;
    }

    return return_value;
}
