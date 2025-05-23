//
// Created by diana on 12-05-2025.
//
#include "Command/Resize.hpp"
#include "../Image.hpp"
#include <algorithm>

namespace prog {
    namespace command {
        // Takes the origin point (x, y), new width and height (w, h),
        // and a fill color used for new areas if the image grows.
        Resize::Resize(int x, int y, int w, int h, Color fill) :
            Command("resize"), m_x(x), m_y(y), m_w(w), m_h(h), m_fill(fill) {}

        // Applies the resize operation to the image.
        Image* Resize::apply(Image* img) {
            // Create a new image with the desired dimensions and fill color.
            Image* result = new Image(m_w, m_h, m_fill);

            // Determine how many pixels we can copy from the original image.
            int copyW = std::min(img->width() - m_x, m_w);
            int copyH = std::min(img->height() - m_y, m_h);

            // Only proceed with copying if the coordinates are within bounds.
            if (m_x < img->width() && m_y < img->height() && copyW > 0 && copyH > 0) {
                for (int x = 0; x < copyW; ++x) {
                    for (int y = 0; y < copyH; ++y) {
                        // Copy pixel from original image (offset by m_x, m_y) into result.
                        result->at(x, y) = img->at(m_x + x, m_y + y);
                    }
                }
            }

            // Free the memory of the original image.
            delete img;

            // Return the resized image.
            return result;
        }

        // Converts the command parameters into a human-readable string.
        std::string Resize::toString() const {
            return name() + " x:" + std::to_string(m_x) + " y:" + std::to_string(m_y) +
                   " w:" + std::to_string(m_w) + " h:" + std::to_string(m_h) +
                   " fill:" + std::to_string(m_fill.red()) + "," +
                   std::to_string(m_fill.green()) + "," + std::to_string(m_fill.blue());
        }

    }
}
