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
            static std::set<std::string> processedFiles; //avoids infinite recursion, so that each script is processed more than one time
            ScrimParser parser;

            for (const auto& filename : m_filenames) {
                if (processedFiles.count(filename)) continue;
                processedFiles.insert(filename);

                std::ifstream file(filename);
                if (!file) continue; //only valid files are processed

                Scrim* scrim = parser.parseScrim(file); //Parses the file and creates one scrim object with instructions
                if (scrim) {
                    img = scrim->run(img); //applys the instructions in the current image
                    delete scrim; //free memory
                }
            }
            return img; //after all the transformations it returns the image
        }
    }
}