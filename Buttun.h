//
// Created by hirata on 09/11/20.
//

#ifndef FORCA4_BUTTUN_H
#define FORCA4_BUTTUN_H
#include <SFML/Graphics.hpp>
#include "textos.h"
#include <iostream>
#include "textbox.h"

using namespace sf;

class Buttun {
private:
    bool onClick= false;
    Sprite play, dicas;

    Color idleColor;
public:
    Buttun();
    ~Buttun();

    //Functions
    void setPlay(Texture &t3);
    void setDicas(Texture &t5);
    void render(RenderWindow &window);
    void renderdica(RenderWindow &window);
    void setBackcolor(Color calor);
    bool isMouseOver(RenderWindow &window);
    bool OverDica(RenderWindow &window);
};


#endif //FORCA4_BUTTUN_H
