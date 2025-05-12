//
// Created by diana on 12-05-2025.
//
#include "Command/Resize.hpp"
#include "../Image.hpp"

#include "Command/Resize.hpp"
#include "../Image.hpp"
#include <algorithm>

namespace prog {
    namespace command {
        Resize::Resize(int x, int y, int w, int h, Color fill) :
            Command("resize"), m_x(x), m_y(y), m_w(w), m_h(h), m_fill(fill) {}

        Image* Resize::apply(Image* img) {
            Image* result = new Image(m_w, m_h, m_fill);

            // Calculate copyable area
            int copyW = std::min(img->width() - m_x, m_w);
            int copyH = std::min(img->height() - m_y, m_h);

            // Only copy if there's overlap
            if (m_x < img->width() && m_y < img->height() && copyW > 0 && copyH > 0) {
                for (int x = 0; x < copyW; ++x) {
                    for (int y = 0; y < copyH; ++y) {
                        result->at(x, y) = img->at(m_x + x, m_y + y);
                    }
                }
            }

            delete img;
            return result;
        }

        std::string Resize::toString() const {
            return name() + " x:" + std::to_string(m_x) + " y:" + std::to_string(m_y) +
                   " w:" + std::to_string(m_w) + " h:" + std::to_string(m_h) +
                   " fill:" + std::to_string(m_fill.red()) + "," +
                   std::to_string(m_fill.green()) + "," + std::to_string(m_fill.blue());
        }
    }
}