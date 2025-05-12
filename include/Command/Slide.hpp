//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_SLIDE_HPP__
#define __PROG_SLIDE_HPP__

#include "../Command.hpp"

namespace prog {
    namespace command {
        class Slide : public Command {
        private:
            int m_dx, m_dy;
        public:
            Slide(int dx, int dy);
            Image* apply(Image* img) override;
        };
    }
}

#endif