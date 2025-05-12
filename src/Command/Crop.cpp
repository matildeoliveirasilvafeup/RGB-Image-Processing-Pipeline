//
// Created by diana on 12-05-2025.
//
#include "Command/Crop.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Crop::Crop(int x, int y, int w, int h) :
            Command("crop"), x(x), y(y), w(w), h(h) {}

        Image* Crop::apply(Image* img) {
            if (!img) return nullptr;

            // Calculate actual crop area
            int x1 = std::max(0, x);
            int y1 = std::max(0, y);
            int x2 = std::min(img->width(), x + w);
            int y2 = std::min(img->height(), y + h);
            int newWidth = x2 - x1;
            int newHeight = y2 - y1;

            if (newWidth <= 0 || newHeight <= 0) {
                return new Image(0, 0); // Empty image
            }

            Image* result = new Image(newWidth, newHeight);

            for (int dx = 0; dx < newWidth; ++dx) {
                for (int dy = 0; dy < newHeight; ++dy) {
                    result->at(dx, dy) = img->at(x1 + dx, y1 + dy);
                }
            }

            delete img;
            return result;
        }

        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }
    }
}