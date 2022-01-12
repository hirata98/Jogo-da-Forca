//
// Created by hirata on 20/10/20.
//

#include "textos.h"

textos::textos(){
    fontes();
    caracteristicas();
}

textos::~textos() = default;

//Funcoes
void textos::fontes() {
    this->font.loadFromFile("../Robusta.ttf");
}

void textos::caracteristicas() {

    palavras.setFont(this->font);
    palavras.setString(L"1 - Voce tem apenas 6 tentativas.  2 - Digite apenas uma letra e de enter!!  3 - Para jogar basta clicar em PLAY.  4 - Dus dicas ao clicar na lampada.\n5 - As palavras irão aparecer aleatoriamente conforme vai jogando.  6 - Letras repeditas serão consideradas como erro!!\n7 - Acertando 5 vezes você passa para o nivel dificl e acertando mais cinco ganha o jogo.");
    palavras.setCharacterSize(20);
    palavras.setFillColor(Color::Black);
    palavras.setPosition(20, 522);

    dicas.setPosition(770, 48);
    dicas.setFont(this->font);
    dicas.setCharacterSize(20);
    dicas.setFillColor(Color::Black);
}

void textos::draw(RenderWindow &window) {
    window.draw(this->palavras);
    window.draw(this->dicas);
}

void textos::setDicas(string dica1, string dica2) {
    string aux = dica1 + "\n\n" + dica2;
    this->cont++;
    dicas.setString(aux);
}

int textos::getContDica() {
    return this->cont;
}
