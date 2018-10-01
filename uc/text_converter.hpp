#ifndef TEXT_CONVERTER_HPP
#define TEXT_CONVERTER_HPP

#include <string>

#include <type.hpp>

namespace uc {

class text_converter {
public:
    text_converter();
    ~text_converter();

    void convert();

    void set_text_original(const std::string text_original);
    void set_type(type type);
    std::string get_text_converted() const;

private:
    uc::type type;
    std::string text_original;
    std::string text_converted;
};

}

#endif // TEXT_CONVERTER_HPP
