//
// Created by diana on 12-05-2025.
//
#include "Command/Replace.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        // Takes the oldColor to be replaced by the newColor
        Replace::Replace(Color oldColor, Color newColor) :
            Command("replace"), oldColor(oldColor), newColor(newColor) {}

        // Applies the Replace command to the image.
        // It replaces every pixel that matches oldColor with newColor.
        Image* Replace::apply(Image* img) {
            if (!img) return nullptr; // Safety check: if the image is null, return null.

            // Loop through all pixels of the image.
            for (int x = 0; x < img->width(); ++x) {
                for (int y = 0; y < img->height(); ++y) {

                    // Get reference to the pixel color at (x, y).
                    Color& c = img->at(x, y);

                    // Compare pixel to oldColor using RGB values.
                    if (c.red() == oldColor.red() &&
                        c.green() == oldColor.green() &&
                        c.blue() == oldColor.blue()) {

                        // Replace it with newColor.
                        c = newColor;
                        }
                }
            }

            // Return the modified image (same image object, now with updated colors).
            return img;
        }

        // Returns a string that describes the command.
        // Useful for debugging or logging purposes.
        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " old:" << oldColor << " new:" << newColor;
            return ss.str();
        }

    }
}
