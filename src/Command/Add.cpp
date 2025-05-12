//
// Created by diana on 12-05-2025.
//
#include "Command/Add.hpp"
#include "../PNG.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Add::Add(std::string filename, Color neutral, int x, int y) :
            Command("add"), filename(filename), neutral(neutral), x(x), y(y) {}

        Image* Add::apply(Image* img) {
            if (!img) return nullptr;

            Image* overlay = loadFromPNG(filename);
            if (!overlay) return img;

            for (int ox = 0; ox < overlay->width(); ++ox) {
                for (int oy = 0; oy < overlay->height(); ++oy) {
                    int px = x + ox;
                    int py = y + oy;
                    if (px >= 0 && px < img->width() && py >= 0 && py < img->height()) {
                        Color src = overlay->at(ox, oy);
                        if (!(src.red() == neutral.red() &&
                              src.green() == neutral.green() &&
                              src.blue() == neutral.blue())) {
                            img->at(px, py) = src;
                              }
                    }
                }
            }

            delete overlay;
            return img;
        }

        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " file:" << filename
               << " neutral:" << neutral << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}