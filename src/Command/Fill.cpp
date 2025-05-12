//
// Created by diana on 12-05-2025.
//
#include "Command/Fill.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Fill::Fill(int x, int y, int w, int h, Color color) :
            Command("fill"), x(x), y(y), w(w), h(h), color(color) {}

        Image* Fill::apply(Image* img) {
            if (!img) return nullptr;

            for (int dx = 0; dx < w; ++dx) {
                for (int dy = 0; dy < h; ++dy) {
                    int px = x + dx;
                    int py = y + dy;
                    if (px >= 0 && px < img->width() && py >= 0 && py < img->height()) {
                        img->at(px, py) = color;
                    }
                }
            }
            return img;
        }

        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y
               << " w:" << w << " h:" << h << " color:" << color;
            return ss.str();
        }
    }
}