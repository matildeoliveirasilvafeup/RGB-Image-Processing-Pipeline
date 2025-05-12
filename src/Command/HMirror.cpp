//
// Created by diana on 12-05-2025.
//

#include "Command/HMirror.hpp"
#include "../Image.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        HMirror::HMirror() : Command("h_mirror") {}

        Image* HMirror::apply(Image* img) {
            if (!img) return nullptr;

            int width = img->width();
            for (int y = 0; y < img->height(); ++y) {
                for (int x = 0; x < width / 2; ++x) {
                    Color temp = img->at(x, y);
                    img->at(x, y) = img->at(width - 1 - x, y);
                    img->at(width - 1 - x, y) = temp;
                }
            }
            return img;
        }
    }
}