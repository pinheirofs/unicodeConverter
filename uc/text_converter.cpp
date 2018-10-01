#include <codecvt>
#include <locale>
#include <string>
#include <sstream>

#include <type.hpp>

#include "text_converter.hpp"

using std::codecvt_utf8;
using std::string;
using std::stringstream;
using std::wstring_convert;
using std::u32string;
using uc::type;

namespace uc {

text_converter::text_converter() {}

text_converter::~text_converter() {}

void text_converter::convert() {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> converter;
    u32string textUnicode = converter.from_bytes(text_original);

    stringstream ss;
    for (char32_t c : textUnicode) {
        uint32_t character = static_cast<uint32_t>(c);

        if (character < 0x80) {
            ss << static_cast<char>(c);
        } else {
            ss << "@#";
            ss << std::uint_least32_t(c);
            ss << ";";
        }
    }

    ss >> text_converted;
}

void text_converter::set_text_original(const std::string text_original) { this->text_original = text_original; }

void text_converter::set_type(enum type type) { this->type = type; }

string text_converter::get_text_converted() const { return text_converted; }

}
