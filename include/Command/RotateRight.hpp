//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_ROTATERIGHT_HPP__
#define __PROG_ROTATERIGHT_HPP__

#include "../Command.hpp"

namespace prog {
    namespace command {
        class RotateRight : public Command {
        public:
            RotateRight();
            Image* apply(Image* img) override;
        };
    }
}

#endif