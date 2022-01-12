#include <SFML/Graphics.hpp>
#include "textos.h"
#include <iostream>
#include <fstream>
#include "textbox.h"
#include "Buttun.h"

using namespace sf;
using namespace std;

int main(){
    textos Textos;
    string aux;
    Text nivel;
    vector <string> textArq, vecPalavras, textArqDificil;
    textbox Box(true);
    bool start= false, start2= true, startdica= false;
    int i, linhas=0, cont=9999, linhas2=0;

    ifstream arq("../arq.txt");    //ARQUIVO CONTENDO AS PALAVRAS E DICAS
    if (arq.is_open()){
        while (!arq.eof()){
            getline(arq, aux);
            textArq.push_back(aux);
            linhas++;
        }
    }else cout<<"erro"<<endl;
    arq.close();

    ifstream arq2("../dificil.txt");
    if (arq2.is_open()){
        while (!arq2.eof()){
            getline(arq2, aux);
            textArqDificil.push_back(aux);
            linhas2++;
        }
    }else cout<<"erro"<<endl;

    RenderWindow window(VideoMode(1092, 655),"Jogo da Forca");

    Font font;
    font.loadFromFile("../Robusta.ttf");

    nivel.setFont(font);
    nivel.setCharacterSize(30);
    nivel.setFillColor(Color::Magenta);
    nivel.setString(L"Você esta no nivel dificil!!");
    nivel.setPosition(800, 350);

    Box.setParametros(font);
    Box.setBoneco();
    Box.limite(true, 1);

    Texture t1, t2, t3, t4, t5, t6;
    t1.loadFromFile("../imagens/deserto.jpg");
    t2.loadFromFile("../imagens/forca.png");
    t3.loadFromFile("../imagens/play.png");
    t5.loadFromFile("../imagens/tips.png");
    t6.loadFromFile("../imagens/win.png");

    Sprite sBackgorund(t1);
    Sprite boneco(t2), win(t6);

    win.setPosition(300, 100);

    boneco.setPosition(20, 20);

    Buttun playbuttun;
    playbuttun.setPlay(t3);
    playbuttun.setDicas(t5);
    while (window.isOpen())
    {
        Event evnt;
        if (Box.getCont() >= 5 && Box.getCont() < 10 && start2) {
            srand(time(NULL));
            do{
                i = rand() % 100;
            }while (i>linhas2 || i%3!=0 || i == cont);
            cont = i;
            Box.setPalavras(textArqDificil[i]);
            start2 = false;
        }
        if (start2 && Box.getCont() < 5) {
            srand(time(NULL));
             do{
                i = rand() % 100;
             }while (i>linhas || i%3!=0 || i == cont);
             cont = i;
             Box.setPalavras(textArq[i]);
            start2 = false;
        }
        if (startdica && Textos.getContDica()<5){
            Textos.setDicas(textArq[i+1], textArq[i+2]);
            startdica = false;
        }else if (startdica && Textos.getContDica()>=5 && Textos.getContDica() < 10){
            Textos.setDicas(textArqDificil[i+1], textArqDificil[i+2]);
            startdica = false;
        }
        Box.seSelected(true);
        if (Keyboard::isKeyPressed(Keyboard::Enter)){
            if (Box.again()){
                start2 = true;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) Box.seSelected(false);
        while (window.pollEvent(evnt))
            switch (evnt.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::TextEntered:
                    if (start) Box.typeON(evnt);
                    break;
                case Event::MouseButtonPressed:
                        if (Mouse::isButtonPressed(Mouse::Left )){
                            if (playbuttun.isMouseOver(window)) {
                                start=true;
                            }
                            if (playbuttun.OverDica(window))startdica = true;
                        }
                    break;
                case Event::MouseMoved:
                    if (playbuttun.isMouseOver(window)){
                        playbuttun.setBackcolor(Color::Green);
                    }else playbuttun.setBackcolor(Color::White);
                    break;
            }
        window.clear();

        window.draw(sBackgorund);
        window.draw(boneco);
        if (Box.getCont() >= 5) window.draw(nivel);
        Textos.draw(window);
        Box.draw(window);
        if (!startdica) playbuttun.renderdica(window);
        if (!start) playbuttun.render(window);
        if (Box.getCont() >= 10) window.draw(win);
        window.display();
    }
    return 0;
}