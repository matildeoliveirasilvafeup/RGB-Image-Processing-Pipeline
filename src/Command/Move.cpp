//
// Created by diana on 12-05-2025.
//
#include "Command/Move.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Move::Move(int dx, int dy, Color fill) :
            Command("move"), dx(dx), dy(dy), fill(fill) {}

        Image* Move::apply(Image* img) {
            if (!img) return nullptr;

            Image* result = new Image(img->width(), img->height(), fill);

            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height(); ++y) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (newX >= 0 && newX < img->width() &&
                        newY >= 0 && newY < img->height()) {
                        result->at(newX, newY) = img->at(x, y);
                        }
                }
            }

            delete img;
            return result;
        }

        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " dx:" << dx << " dy:" << dy << " fill:" << fill;
            return ss.str();
        }
    }
}