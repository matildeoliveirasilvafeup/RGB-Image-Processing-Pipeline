// Created by hermi on 22/05/2025.

#pragma once
#include "Command.hpp"

namespace prog {

    class ScaleUp : public Command {
    private:
        int factor_x, factor_y;

    public:
        ScaleUp(int fx, int fy);
        Image* apply(Image* img) override;
    };

}
