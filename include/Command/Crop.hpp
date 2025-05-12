//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_CROP_HPP__
#define __PROG_CROP_HPP__

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        class Crop : public Command {
        private:
            int x, y, w, h;
        public:
            Crop(int x, int y, int w, int h);
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}

#endif