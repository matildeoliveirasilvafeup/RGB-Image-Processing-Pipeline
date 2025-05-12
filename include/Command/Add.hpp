//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_ADD_HPP__
#define __PROG_ADD_HPP__

#include "../Command.hpp"
#include "../Color.hpp"
#include "../PNG.hpp"
namespace prog {
    namespace command {
        class Add : public Command {
        private:
            std::string filename;
            Color neutral;
            int x, y;
        public:
            Add(std::string filename, Color neutral, int x, int y);
            Image* apply(Image* img) override;
            std::string toString() const override;
        };
    }
}

#endif