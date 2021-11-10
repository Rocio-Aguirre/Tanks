#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

#include "gameplay.h"

int main()
{
    ///inicialización
    sf::RenderWindow window(sf::VideoMode(800,600), "TANKS!");
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Gameplay gp;
    ///gameloop
    while(window.isOpen()){
            /// a la bu rar
            ///holis
        //cmd(): eventos o comandos (dato de entrada)
        //update(): donde procesa la info (proceso)
        //draw(): dibujado de lo que procesó (dato de salida)
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        gp.cmd();
        gp.update();

        window.clear(); //borra el dibujo anterior
        /*
        std::map<int, Bloque> blockPositions;
        Bloque amarillo;
        blockPositions.insert(std::make_pair(1, amarillo));
        blockPositions.at(amarillo&);
    */
        gp.draw(window);
        window.display(); //muestra en pantalla
    }
    ///liberación
    return 0;
}
