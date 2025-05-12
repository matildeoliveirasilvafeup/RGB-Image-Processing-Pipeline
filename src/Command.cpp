#include "Command.hpp"

namespace prog {
    Command::Command() : command_name("") {}

    Command::Command(std::string command_name) : command_name(command_name) {}

    Command::~Command() {}

    std::string Command::toString() const {
        return name();
    }

    std::string Command::name() const {
        return command_name;
    }
}

std::ostream &operator<<(std::ostream &output, const prog::Command &command) {
    output << command.toString();
    return output;
}