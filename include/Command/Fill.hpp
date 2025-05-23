//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_FILL_HPP__
#define __PROG_FILL_HPP__

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        private:
            int x, y, w, h;
            Color color;
        public:
            Fill(int x, int y, int w, int h, Color color);
            Image* apply(Image* img) override;

            std::string toString() const override; //conversão para string
        };
    }
}

#endif