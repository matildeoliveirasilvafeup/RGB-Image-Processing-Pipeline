//
// Created by hermi on 12-05-2025.
//
#include "Command/Chain.hpp"
#include "../ScrimParser.hpp"
#include <fstream>
#include <set>

namespace prog {
    namespace command {
        Chain::Chain(const std::vector<std::string>& filenames) :
            Command("chain"), m_filenames(filenames) {}

        Image* Chain::apply(Image* img) {
            static std::set<std::string> processedFiles;
            ScrimParser parser;

            for (const auto& filename : m_filenames) {
                if (processedFiles.count(filename)) continue;
                processedFiles.insert(filename);

                std::ifstream file(filename);
                if (!file) continue;

                Scrim* scrim = parser.parseScrim(file);
                if (scrim) {
                    img = scrim->run(img);
                    delete scrim;
                }
            }
            processedFiles.clear();
            return img;
        }
    }
}