#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <string>

namespace uc {

enum type {
    ATECH,
    NO_TYPE
};

class parameters {
public:
    parameters(int argc, char *argv[]);
    ~parameters();
    bool is_valid() const;
    std::string get_text() const;
    type get_type() const;
private:
    static const std::string COMMAND_NAME;
    
    void parse_arguments(int argc, char *argv[]);
    void process_type(std::string type);
    void validate();

    bool valid;
    std::string text;

    type type;
};

}

#endif // PARAMETERS_HPP
