#ifndef PROJECT_COMMAND_HPP
#define PROJECT_COMMAND_HPP

#include "Image.hpp"
#include <string>

namespace prog {
    class Command {
    public:
        Command();
        Command(std::string command_name);
        virtual ~Command() = 0;

        virtual Image *apply(Image *img) = 0;
        virtual std::string toString() const;
        std::string name() const;

    private:
        std::string command_name;
    };
}

std::ostream &operator<<(std::ostream &output, const prog::Command &command);

#endif