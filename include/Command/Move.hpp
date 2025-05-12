//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_MOVE_HPP__
#define __PROG_MOVE_HPP__

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        class Move : public Command {
        private:
            int dx, dy;
            Color fill;
        public:
            Move(int dx, int dy, Color fill = {0, 0, 0});
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}

#endif