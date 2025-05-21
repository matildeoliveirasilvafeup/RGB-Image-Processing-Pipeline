//
// Created by hermi on 22/05/2025.
//

#include "Command/ScaleUp.hpp"
#include "Image.hpp"

namespace prog {

    // Constructor for the ScaleUp command.
    // Takes the horizontal (fx) and vertical (fy) scale factors.
    ScaleUp::ScaleUp(int fx, int fy)
        : Command("scaleup"), factor_x(fx), factor_y(fy) {}

    // Applies the scale-up operation to the given image.
    Image* ScaleUp::apply(Image* img) {
        // Calculate the new image dimensions
        int new_width = img->width() * factor_x;
        int new_height = img->height() * factor_y;

        // Create a new image with the updated size
        Image* new_img = new Image(new_width, new_height);

        // Go through each pixel in the original image
        for (int y = 0; y < img->height(); ++y) {
            for (int x = 0; x < img->width(); ++x) {
                // Get the color at the current pixel
                Color c = img->at(x, y);

                // Fill a block of size factor_x × factor_y with that color
                for (int dy = 0; dy < factor_y; ++dy) {
                    for (int dx = 0; dx < factor_x; ++dx) {
                        new_img->at(x * factor_x + dx, y * factor_y + dy) = c;
                    }
                }
            }
        }

        // Clean up the original image
        delete img;

        // Return the scaled-up image
        return new_img;
    }

}
