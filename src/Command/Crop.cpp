//
// Created by diana on 12-05-2025.
//
#include "Command/Crop.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        // Takes the top-left corner (x, y) and the width and height (w, h) of the crop area.
        Crop::Crop(int x, int y, int w, int h) :
            Command("crop"), x(x), y(y), w(w), h(h) {}

        // Applies the Crop command to the given image.
        // It returns a new image containing only the cropped region.
        Image* Crop::apply(Image* img) {
            if (!img) return nullptr;  // Check if the input image is null.

            // Ensure the crop coordinates stay within the bounds of the image.
            int x1 = std::max(0, x); // Clamp left to at least 0.
            int y1 = std::max(0, y); // Clamp top to at least 0.
            int x2 = std::min(img->width(), x + w);  // Clamp right edge to image width.
            int y2 = std::min(img->height(), y + h); // Clamp bottom edge to image height.

            int newWidth = x2 - x1;
            int newHeight = y2 - y1;

            // If the calculated crop area is invalid (zero or negative size), return an empty image.
            if (newWidth <= 0 || newHeight <= 0) {
                return new Image(0, 0);
            }

            // Create a new image with the cropped dimensions.
            Image* result = new Image(newWidth, newHeight);

            // Copy pixels from the original image into the new cropped image.
            for (int dx = 0; dx < newWidth; ++dx) {
                for (int dy = 0; dy < newHeight; ++dy) {
                    result->at(dx, dy) = img->at(x1 + dx, y1 + dy);
                }
            }

            delete img; // Free memory of the original image.
            return result; // Return the new cropped image.
        }

        // Returns a string description of this command.
        // Useful for logging or debugging.
        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h;
            return ss.str();
        }

    }
}
