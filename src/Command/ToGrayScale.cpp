//
// Created by diana on 12-05-2025.
//
#include "Command/ToGrayScale.hpp"
#include "../Image.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        ToGrayScale::ToGrayScale() : Command("to_gray_scale") {}

        Image* ToGrayScale::apply(Image* img) {
            if (!img) return nullptr;

            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height(); ++y) {
                    Color& c = img->at(x, y);
                    rgb_value gray = (c.red() + c.green() + c.blue()) / 3;
                    c.red() = gray;
                    c.green() = gray;
                    c.blue() = gray;
                }
            }
            return img;
        }
    }
}