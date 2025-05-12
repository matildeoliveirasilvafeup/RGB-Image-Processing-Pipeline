//
// Created by diana on 12-05-2025.
//
#include "Command/Replace.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Replace::Replace(Color oldColor, Color newColor) :
            Command("replace"), oldColor(oldColor), newColor(newColor) {}

        Image* Replace::apply(Image* img) {
            if (!img) return nullptr;

            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height(); ++y) {
                    Color& c = img->at(x, y);
                    if (c.red() == oldColor.red() &&
                        c.green() == oldColor.green() &&
                        c.blue() == oldColor.blue()) {
                        c = newColor;
                        }
                }
            }
            return img;
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " old:" << oldColor << " new:" << newColor;
            return ss.str();
        }
    }
}