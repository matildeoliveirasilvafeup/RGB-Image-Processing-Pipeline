//
// Created by diana on 12-05-2025.
//
#include "Command/Fill.hpp"
#include "../Image.hpp"
#include "../Color.hpp"
#include <sstream>

namespace prog {
    namespace command {
        // Construtor da classe Fill
        // Inicializa os parâmetros do preenchimento:
        // x, y: coordenadas do canto superior esquerdo
        // w, h: largura e altura da área
        // color: cor de preenchimento

        Fill::Fill(int x, int y, int w, int h, Color color) :
            Command("fill"), x(x), y(y), w(w), h(h), color(color) {}

        Image* Fill::apply(Image* img) {
            // Aplica o preenchimento na imagem
            if (!img) return nullptr; // Verifica se a imagem é válida

            // Percorre cada pixel na área definida
            for (int dx = 0; dx < w; ++dx) {
                for (int dy = 0; dy < h; ++dy) {
                    // Calcula a posição do pixel
                    int px = x + dx;
                    int py = y + dy;
                    // Verifica se o pixel está dentro dos limites da imagem
                    if (px >= 0 && px < img->width() && py >= 0 && py < img->height()) {
                        // Aplica a cor no pixel
                        img->at(px, py) = color;
                    }
                }
            }
            return img;
        }

        // Converte o comando para uma string
        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y
               << " w:" << w << " h:" << h << " color:" << color;
            return ss.str();
        }
    }
}