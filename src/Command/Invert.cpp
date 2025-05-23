//
// Created by diana on 12-05-2025.
//

#include "Command/Invert.hpp"
#include "../Image.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {

        Invert::Invert() : Command("invert") {} // construtor - Inicializa a classe base Command com o nome "invert"

        Image* Invert::apply(Image* img) { // Implementação do métod apply que realiza a inversão de cores
            if (!img) return nullptr;// Verifica se o ponteiro da imagem é válido

            // Percorre todos os pixels da imagem (largura x altura)

            for (int x = 0; x < img->width(); ++x) { //largura
                for (int y = 0; y < img->height(); ++y) { //altura

                    Color& c = img->at(x, y); //referência para pixel atual
                    //inversão dos componentes
                    c.red() = 255 - c.red();
                    c.green() = 255 - c.green();
                    c.blue() = 255 - c.blue();
                }
            }
            return img; //retorno da imagem modificada
        }
    }
}