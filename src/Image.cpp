#include "Image.hpp"
#include <stdexcept>

namespace prog {
    Image::Image(int w, int h, const Color &fill) :
        m_width(w), m_height(h) {
        m_pixels = new Color*[w];
        for (int x = 0; x < w; ++x) {
            m_pixels[x] = new Color[h];
            for (int y = 0; y < h; ++y) {
                m_pixels[x][y] = fill;
            }
        }
    }

    Image::~Image() {
        for (int x = 0; x < m_width; ++x) {
            delete[] m_pixels[x];
        }
        delete[] m_pixels;
    }

    int Image::width() const { return m_width; }
    int Image::height() const { return m_height; }

    Color &Image::at(int x, int y) {
        if (x < 0 || x >= m_width || y < 0 || y >= m_height) {
            throw std::out_of_range("Image coordinates out of bounds");
        }
        return m_pixels[x][y];
    }

    const Color &Image::at(int x, int y) const {
        if (x < 0 || x >= m_width || y < 0 || y >= m_height) {
            throw std::out_of_range("Image coordinates out of bounds");
        }
        return m_pixels[x][y];
    }
}