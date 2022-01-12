//
// Created by hirata on 22/10/20.
//

#include "textbox.h"

textbox::textbox(bool sal) {
    boxSelected = sal;
    if (sal) Textbox.setString("_");
    else Textbox.setString("");
}

textbox::~textbox() {

}
void textbox::Input(int chartype) {
    if (chartype != DELETE_KEY && chartype != ENTER_KEY && chartype != ESCAPE_KEY){
        text << static_cast<char>(chartype);
    }else if (chartype == DELETE_KEY){
        if(text.str().length() > 0){
            deletechar();
        }
    }
    else if (chartype == ENTER_KEY){
        int i=0, j=0;
        int verif=0, verif2=0, verif3=0;
        string atual = text.str();

        atual[0] = tolower(atual[0]);
        if (!tryAgain) {
            palavras2.setString(' ');
        }
        while (j < jafoi.length()) {
            if (atual[0] == jafoi[j]){
                verif3 =1;
            }
            j++;
        }
        while (i<palavraAtual.length()){
            if(atual[0] == tolower(palavraAtual[i]) && verif3 == 0){
                val++;
                verif=1;
                aleatorio[i] = palavraAtual[i];
            }else if (verif == 1) verif2 = 1;
            i++;
        }
        this->jafoi = jafoi+atual;
        letrasjafoi.setString(jafoi);
        if(verif2==0 && verif ==0 && text.str()!="") setDesenhaB();
        if(text.str().length() > 0){
            deletechar();
        }
        if(val < palavraAtual.length()) palavras.setString(aleatorio);
        if(val == palavraAtual.length()){
            palavras.setString(aleatorio);
            palavras2.setString("PARABENS VOCE COMPLETOU\nAperte ENTER para jogar novamente");
            cont++;
            contParts = 0;
            jafoi = ' ';
            this->val=0;
            this->tryAgain = true;
            this->corpo.setTexture(goku.at(6));
        }
    }
    Textbox.setString(text.str()+"_");
    palavras.setString(aleatorio);
}
void textbox::deletechar() {
    string t = text.str();
    string novoT = "";
    for(int i = 0; i < t.length()-1; ++i) {
        novoT += t[i];
    }
    text.str("");
    text << novoT;

    Textbox.setString(text.str());
}

void textbox::setParametros(const Font& font) {
    Textbox.setFont(font);
    Textbox.setPosition(480, 450);
    Textbox.setCharacterSize(60);
    Textbox.setFillColor(Color::Black);

    palavras.setFont(font);
    palavras.setCharacterSize(60);
    palavras.setFillColor(Color::Green);
    palavras.setPosition(300, 100);

    palavras2.setFont(font);
    palavras2.setCharacterSize(60);
    palavras2.setFillColor(Color::Green);
    palavras2.setPosition(300, 150);

    letrasjafoi.setFont(font);
    letrasjafoi.setCharacterSize(60);
    letrasjafoi.setFillColor(Color::Black);
    letrasjafoi.setPosition(300, 20);

}
void textbox::limite(bool logica, int L) {
    this->limit = logica;
    this->lim = L;
}
void textbox::seSelected(bool selected) {
    boxSelected = selected;
    if (!selected){
        string t = text.str();
        string novoT = "";
        for(int i = 0; i < t.length(); ++i) {
            novoT += t[i];
        }
        Textbox.setString(novoT);
    }
}
void textbox::draw(RenderWindow &window) {
    window.draw(Textbox);
    window.draw(palavras);
    window.draw(palavras2);
    window.draw(corpo);
    window.draw(letrasjafoi);
}
void textbox::typeON(Event entrada) {
    if (boxSelected){
        int charCliclado = entrada.text.unicode;
        if (charCliclado < 128){
            if (limit){
                if (text.str().length() <= this->lim){
                    Input(charCliclado);
                }else if (text.str().length() > this->lim && charCliclado == DELETE_KEY){
                    deletechar();
                }
            }else{
                Input(charCliclado);
            }
        }
    }
}
void textbox::setBoneco(){
    Texture moment;
    moment.loadFromFile("../imagens/goku.png");
    goku.push_back(moment);
    moment.loadFromFile("../imagens/goku2.png");
    goku.push_back(moment);
    moment.loadFromFile("../imagens/goku3.png");
    goku.push_back(moment);
    moment.loadFromFile("../imagens/goku4.png");
    goku.push_back(moment);
    moment.loadFromFile("../imagens/goku5.png");
    goku.push_back(moment);
    moment.loadFromFile("../imagens/goku6.png");
    goku.push_back(moment);
    moment.loadFromFile("../imagens/gokuNULL.png");
    goku.push_back(moment);
}

void textbox::setDesenhaB() {
    corpo.setPosition(185,200);
    if (contParts == 0) {
        corpo.setTexture(goku.at(0));
    }
    else if (contParts == 1) {
        corpo.setTexture(goku.at(1));
    }
    else if (contParts == 2) {
        corpo.setTexture(goku.at(2));
    }
    else if (contParts == 3) {
        corpo.setTexture(goku.at(3));
    }
    else if (contParts == 4) {
        corpo.setTexture(goku.at(4));
    }else if (contParts == 5){
        corpo.setTexture(goku.at(5));
        palavras2.setString("VOCE PERDEU!!\nAperte ENTER para jogar novamente");
        this->val = 0;
        this->tryAgain = true;
        jafoi = ' ';
        contParts = 0;
        corpo.setTexture(goku.at(6));
    }
    contParts++;
}

void textbox::setPalavras(string aux) {
    string aux2;
    aleatorio = aux2;
    palavraAtual = aux;
    for (int i = 0; i < aux.length(); ++i) {
        if (palavraAtual[i]=='-'){
            val = 1;
            aleatorio = aleatorio+'-';
        }
        else aleatorio = aleatorio+'_';
    }
}
bool textbox::again() {
    if (tryAgain) {
        this->tryAgain = false;
        return true;
    }else return false;
}

int textbox::getCont() {
    return this->cont;
}


