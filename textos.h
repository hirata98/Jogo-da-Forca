//
// Created by hirata on 20/10/20.
//
#ifndef FORCA4_TEXTOS_H
#define FORCA4_TEXTOS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

using namespace sf;
using namespace std;

class textos {
private:
    Font font;
    Text palavras, dicas;
    int cont=0;
public:
    textos();
    ~textos();

    //funcoes
    void fontes();
    void caracteristicas();
    void setDicas(string, string);
    void draw(RenderWindow &window);
    int getContDica();

};


#endif //FORCA4_TEXTOS_H
