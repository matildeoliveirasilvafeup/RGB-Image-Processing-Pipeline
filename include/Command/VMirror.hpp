//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_VMIRROR_HPP__
#define __PROG_VMIRROR_HPP__

#include "../Command.hpp"

namespace prog {
    namespace command {
        class VMirror : public Command {
        public:
            VMirror();
            Image* apply(Image* img) override;
        };
    }
}

#endif