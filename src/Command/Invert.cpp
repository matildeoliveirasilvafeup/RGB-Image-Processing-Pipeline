//
// Created by diana on 12-05-2025.
//

#include "Command/Invert.hpp"
#include "../Image.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        Invert::Invert() : Command("invert") {}

        Image* Invert::apply(Image* img) {
            if (!img) return nullptr;

            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height(); ++y) {
                    Color& c = img->at(x, y);
                    c.red() = 255 - c.red();
                    c.green() = 255 - c.green();
                    c.blue() = 255 - c.blue();
                }
            }
            return img;
        }
    }
}