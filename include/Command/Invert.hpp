#ifndef __PROG_INVERT_HPP__
#define __PROG_INVERT_HPP__

#include "../Command.hpp"

namespace prog {
    namespace command {
        class Invert : public Command {
        public:
            Invert();
            Image* apply(Image* img) override;
        };
    }
}

#endif