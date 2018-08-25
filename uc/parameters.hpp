#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

#include <string>

namespace uc {

class parameters {
public:
    parameters(const int argc, const char* argv[]);
    ~parameters();
    bool is_valid() const;
    std::string get_text() const;
private:
    static const std::string COMMAND_NAME;
    
    void parse_arguments(const int argc, const char *argv[]);

    bool valid;
    std::string text;
};

}

#endif // PARAMETERS_HPP
