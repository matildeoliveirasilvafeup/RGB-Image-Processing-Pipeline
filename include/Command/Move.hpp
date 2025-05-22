#ifndef PROG_COMMAND_MOVE_HPP
#define PROG_COMMAND_MOVE_HPP

#include "Command.hpp"

namespace prog {

    // Represents a command to move the image by (dx, dy) pixels
    class Move : public Command {
    public:
        // Constructs the move command with specified displacement values
        Move(int dx, int dy);

        // Applies the move operation to the given image
        Image* apply(Image* img) override;

    private:
        int dx, dy; // Displacement in the x and y directions
    };

}

#endif // PROG_COMMAND_MOVE_HPP
