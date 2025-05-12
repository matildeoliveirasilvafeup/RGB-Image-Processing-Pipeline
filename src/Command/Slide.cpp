//
// Created by diana on 12-05-2025.
//
#include "Command/Slide.hpp"
#include "../Image.hpp"

namespace prog {
    namespace command {
        Slide::Slide(int dx, int dy) : Command("slide"), m_dx(dx), m_dy(dy) {}

        Image* Slide::apply(Image* img) {
            if (!img) return nullptr;

            Image* result = new Image(img->width(), img->height());

            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height(); ++y) {
                    int newX = (x + m_dx) % img->width();
                    int newY = (y + m_dy) % img->height();

                    // Handle negative values
                    if (newX < 0) newX += img->width();
                    if (newY < 0) newY += img->height();

                    result->at(newX, newY) = img->at(x, y);
                }
            }

            delete img;
            return result;
        }
    }
}