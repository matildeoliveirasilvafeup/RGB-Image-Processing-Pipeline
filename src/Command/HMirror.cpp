//
// Created by diana on 12-05-2025.
//

#include "Command/HMirror.hpp"
#include "../Image.hpp"
#include "../Color.hpp"

namespace prog {
    namespace command {
        // Construtor da classe HMirror
        // Inicializa a classe base Command com o nome "h_mirror"
        HMirror::HMirror() : Command("h_mirror") {}


        // Implementação do métod apply
        Image* HMirror::apply(Image* img) {

            if (!img) return nullptr; // Verifica se o ponteiro da imagem é válido

            int width = img->width(); // Obtém a largura da imagem

            // Percorre todas as linhas (altura) da imagem
            for (int y = 0; y < img->height(); ++y) {
                // Percorre apenas metade da largura - evita trocas duplicadas
                for (int x = 0; x < width / 2; ++x) {
                    Color temp = img->at(x, y); // Armazena temporariamente o pixel da esquerda
                    img->at(x, y) = img->at(width - 1 - x, y);// Substitui o pixel da esquerda pelo pixel correspondente da direita
                    img->at(width - 1 - x, y) = temp; // Substitui o pixel da direita pelo pixel temporário (original da esquerda)

                }
            }
            return img;
        }
    }
}