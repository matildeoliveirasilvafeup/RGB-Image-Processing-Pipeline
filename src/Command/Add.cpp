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
        // Takes the overlay image filename, the neutral color (which should be ignored),
        // and the (x, y) position where the overlay will be placed.
        Add::Add(std::string filename, Color neutral, int x, int y) :
            Command("add"), filename(filename), neutral(neutral), x(x), y(y) {}

        // Applies the Add command to the given image.
        // It overlays another image onto 'img', skipping pixels that match the neutral color.
        Image* Add::apply(Image* img) {
            if (!img) return nullptr;  // Check for null input image.

            // Load the overlay image from a PNG file.
            Image* overlay = loadFromPNG(filename);
            if (!overlay) return img;  // If overlay can't be loaded, return the original image.

            // Loop over each pixel in the overlay image.
            for (int ox = 0; ox < overlay->width(); ++ox) {
                for (int oy = 0; oy < overlay->height(); ++oy) {
                    // Calculate position in the base image.
                    int px = x + ox;
                    int py = y + oy;

                    // Check if the position is within the bounds of the base image.
                    if (px >= 0 && px < img->width() && py >= 0 && py < img->height()) {
                        Color src = overlay->at(ox, oy);

                        // Only copy the pixel if it is not equal to the neutral color.
                        if (!(src.red() == neutral.red() &&
                              src.green() == neutral.green() &&
                              src.blue() == neutral.blue())) {
                            img->at(px, py) = src;
                        }
                    }
                }
            }

            // Clean up memory by deleting the overlay image.
            delete overlay;
            return img;  // Return the modified image.
        }

        // Returns a string description of this command, useful for debugging or logs.
        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " file:" << filename
               << " neutral:" << neutral << " x:" << x << " y:" << y;
            return ss.str();
        }

    }
}
