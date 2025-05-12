//
// Created by diana on 12-05-2025.
//
#include "Command/RotateRight.hpp"
#include "../Image.hpp"

namespace prog {
    namespace command {
        RotateRight::RotateRight() : Command("rotate_right") {}

        Image* RotateRight::apply(Image* img) {
            if (!img) return nullptr;

            Image* result = new Image(img->height(), img->width());

            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height(); ++y) {
                    result->at(img->height() - 1 - y, x) = img->at(x, y);
                }
            }

            delete img;
            return result;
        }
    }
}