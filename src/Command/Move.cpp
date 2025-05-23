#include "Command/Move.hpp"
#include "Image.hpp"

namespace prog {

    // Initializes displacement in x and y directions
    Move::Move(int dx, int dy)
        : Command("move"), dx(dx), dy(dy) {}

    // Applies the move operation to the image by shifting all pixels by dx and dy
    Image* Move::apply(Image* img) {
        int w = img->width();   // Get image width
        int h = img->height();  // Get image height

        // Create a new image with the same dimensions, filled with white by default
        Image* result = new Image(w, h, Color(255, 255, 255));

        // Iterate over each pixel in the original image
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int new_x = x + dx;  // Calculate new x position
                int new_y = y + dy;  // Calculate new y position

                // Only move pixels that fall within the bounds of the result image
                if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h) {
                    result->at(new_x, new_y) = img->at(x, y);
                }
            }
        }

        // Free the original image memory
        delete img;

        // Return the new image with the pixels moved
        return result;
    }

}
