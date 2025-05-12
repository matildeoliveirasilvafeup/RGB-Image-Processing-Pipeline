//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_ROTATELEFT_HPP__
#define __PROG_ROTATELEFT_HPP__

#include "../Command.hpp"

namespace prog {
    namespace command {
        class RotateLeft : public Command {
        public:
            RotateLeft();
            Image* apply(Image* img) override;
        };
    }
}

#endif