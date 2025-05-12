#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    // Constructors
    Color::Color() : m_red(0), m_green(0), m_blue(0) {}

    Color::Color(const Color &other) :
        m_red(other.m_red), m_green(other.m_green), m_blue(other.m_blue) {}

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) :
        m_red(red), m_green(green), m_blue(blue) {}

    // Assignment operator
    Color& Color::operator=(const Color& other) {
        if (this != &other) {  // Self-assignment check
            m_red = other.m_red;
            m_green = other.m_green;
            m_blue = other.m_blue;
        }
        return *this;
    }

    // Accessors
    rgb_value Color::red() const { return m_red; }
    rgb_value Color::green() const { return m_green; }
    rgb_value Color::blue() const { return m_blue; }

    // Mutable references
    rgb_value &Color::red() { return m_red; }
    rgb_value &Color::green() { return m_green; }
    rgb_value &Color::blue() { return m_blue; }
}

// Stream operators
istream &operator>>(istream &input, prog::Color &c) {
    int r, g, b;
    input >> r >> g >> b;
    c.red() = static_cast<prog::rgb_value>(r);
    c.green() = static_cast<prog::rgb_value>(g);
    c.blue() = static_cast<prog::rgb_value>(b);
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) {
    output << static_cast<int>(c.red()) << ":"
           << static_cast<int>(c.green()) << ":"
           << static_cast<int>(c.blue());
    return output;
}