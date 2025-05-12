//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_TOGRAYSCALE_HPP__
#define __PROG_TOGRAYSCALE_HPP__

#include "../Command.hpp"

namespace prog {
    namespace command {
        class ToGrayScale : public Command {
        public:
            ToGrayScale();
            Image* apply(Image* img) override;
        };
    }
}

#endif