#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

#include "app.h"
#include "archivos.h"

int main()
{
//    int pos=0;
//    Levels aux;
//    aux.ingresarMapa();
//    aux.grabarDisco();
//    while(aux.leerDisco(pos++))
//    {
//        aux.mostrar();
//    }

//    char _nick[6]="HOLIS";
//
//    int _num=12;
//
//    int a = 10;
//    char *intStr = itoa(a,_nick,10);
//
//
//    sf::Font _font;
//    sf::Text _text;
//
//    const sf::String _string[5]="UENAS";
//    _font.loadFromFile("resources/game_over.ttf");
//
//    _text.setFont(_font);
//    _text.setColor(sf::Color::White);
//    _text.setString(intStr);
//    _text.setPosition(sf::Vector2f(20,20));
//    _text.setCharacterSize(50);
//
//
//    sf::RenderWindow window(sf::VideoMode(200, 200), "asddd");
//
//     while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(_text);
//        window.display();
//    }

    setlocale(LC_ALL, "");
    app app(672,480,"TANQUESITOS");
}
