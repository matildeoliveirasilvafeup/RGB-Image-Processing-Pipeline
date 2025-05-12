//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_REPLACE_HPP__
#define __PROG_REPLACE_HPP__

#include "../Command.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        class Replace : public Command {
        private:
            Color oldColor;
            Color newColor;
        public:
            Replace(Color oldColor, Color newColor);
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}

#endif