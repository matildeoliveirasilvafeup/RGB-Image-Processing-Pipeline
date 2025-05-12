//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_RESIZE_HPP__
#define __PROG_RESIZE_HPP__

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        class Resize : public Command {
        private:
            int m_x, m_y, m_w, m_h;
            Color m_fill;
        public:
            Resize(int x, int y, int w, int h, Color fill);
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}

#endif