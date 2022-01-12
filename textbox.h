//
// Created by hirata on 22/10/20.
//

#ifndef FORCA4_TEXTBOX_H
#define FORCA4_TEXTBOX_H
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "textos.h"


using namespace sf;
using namespace std;
class textbox {
private:
    string palavraAtual, aleatorio, jafoi;
    Text Textbox, palavras, palavras2, letrasjafoi;
    vector <Texture> goku;
    Sprite corpo;
    ostringstream text;
    int lim, val=0, contParts=0, cont=0;
    bool boxSelected=false, limit= false, tryAgain= false;

    void Input(int chartype);
    void deletechar();

public:
    explicit textbox(bool);
    ~textbox();

    void setPalavras(string);
    void setParametros(const Font&);
    void limite(bool, int);
    void seSelected(bool);
    void setBoneco();
    void setDesenhaB();
    void draw(RenderWindow &window);
    void typeON(Event);
    bool again();
    int getCont();

};


#endif //FORCA4_TEXTBOX_H
