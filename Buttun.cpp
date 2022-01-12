//
// Created by hirata on 09/11/20.
//

#include "Buttun.h"

Buttun::Buttun() {}

Buttun::~Buttun() {

}
void Buttun::render(RenderWindow &window) {
    window.draw(this->play);
}

void Buttun::setBackcolor(Color color) {
    idleColor = color;
    this->play.setColor(this->idleColor);
}
bool Buttun::isMouseOver(RenderWindow &window) {
    float mouseX = Mouse::getPosition(window).x;
    float mouseY = Mouse::getPosition(window).y;

    float btnPosX = this->play.getPosition().x;
    float btnPosY = this->play.getPosition().y;


    float btnXposWidth = this->play.getPosition().x + this->play.getLocalBounds().width;
    float btnYposHeight = this->play.getPosition().y + this->play.getLocalBounds().height;



    if (mouseX < btnXposWidth && mouseX > btnPosX && mouseY < btnYposHeight && mouseY > btnPosY) return true;
    else return false;
}
void Buttun::setPlay(Texture &t3) {
    this->play.setPosition(400, 200);
    this->play.setTexture(t3);
}

void Buttun::setDicas(Texture &t5) {
    this->dicas.setPosition(900, 120);
    this->dicas.setTexture(t5);
}

void Buttun::renderdica(RenderWindow &window) {
    window.draw(this->dicas);
}

bool Buttun::OverDica(RenderWindow &window) {
    float mouseX = Mouse::getPosition(window).x;
    float mouseY = Mouse::getPosition(window).y;

    float btnPosXdicas = this->dicas.getPosition().x;
    float btnPosYdicas = this->dicas.getPosition().y;

    float btnXposWidthDicas = this->dicas.getPosition().x + this->dicas.getLocalBounds().width;
    float btnYposHeightDicas = this->dicas.getPosition().y + this->dicas.getLocalBounds().height;

    if (mouseX < btnXposWidthDicas && mouseX > btnPosXdicas && mouseY < btnYposHeightDicas && mouseY > btnPosYdicas) return true;
    return false;
}
