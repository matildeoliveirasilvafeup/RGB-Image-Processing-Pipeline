//
// Created by diana on 12-05-2025.
//
#include "Command/RotateLeft.hpp"
#include "../Image.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        RotateLeft::RotateLeft() : Command("rotate_left") {}

        Image* RotateLeft::apply(Image* img) {
            if (!img) return nullptr;

            int oldWidth = img->width();
            int oldHeight = img->height();
            Image* result = new Image(oldHeight, oldWidth);

            for (int x = 0; x < oldWidth; ++x) {
                for (int y = 0; y < oldHeight; ++y) {
                    result->at(y, oldWidth - 1 - x) = img->at(x, y);
                }
            }

            delete img;
            return result;
        }
    }
}