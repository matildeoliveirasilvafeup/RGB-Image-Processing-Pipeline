//
// Created by diana on 12-05-2025.
//

#ifndef __PROG_CHAIN_HPP__
#define __PROG_CHAIN_HPP__

#include "../Command.hpp"
#include "../ScrimParser.hpp"
#include <vector>
#include <string>
#include <set>

namespace prog {
    namespace command {
        class Chain : public Command {
        private:
            std::vector<std::string> m_filenames;
        public:
            Chain(const std::vector<std::string>& filenames);
            Image* apply(Image* img) override;
        };
    }
}

#endif