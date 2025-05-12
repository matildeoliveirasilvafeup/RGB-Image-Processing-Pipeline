//
// Created by diana on 12-05-2025.
//
#include "Command/VMirror.hpp"
#include "../Image.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        VMirror::VMirror() : Command("v_mirror") {}

        Image* VMirror::apply(Image* img) {
            if (!img) return nullptr;

            int height = img->height();
            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < height / 2; ++y) {
                    Color temp = img->at(x, y);
                    img->at(x, y) = img->at(x, height - 1 - y);
                    img->at(x, height - 1 - y) = temp;
                }
            }
            return img;
        }
    }
}