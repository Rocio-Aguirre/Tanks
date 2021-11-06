#include <SFML/Graphics.hpp>
#include <iostream>

#include "gameplay.h"
#include "object.h"

int main()
{
    ///inicialización
    sf::RenderWindow window(sf::VideoMode(800,600), "TANKS!");
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ///---
    ///object Obj(20,20,ST_YELLOW_TANK);

    sf::Texture * texture = new sf::Texture();
    texture->loadFromFile("resources/textures.png");
    sf::Sprite * TANK_1 = new sf::Sprite(*texture,sf::IntRect(3,5,15,13));

    std::cout << SpriteConfig().getData(ST_RED_BLOCK)->d_sprite->getGlobalBounds().height << std::endl;
    //std::cout << TANK_1->getGlobalBounds().width << std::endl;
    //std::cout << TANK_1->getGlobalBounds().height << std::endl;

    TANK_1->setPosition(30,30);
    //TANK_1->scale(32/TANK_1->getGlobalBounds().width,32/TANK_1->getGlobalBounds().height);

    //std::cout << TANK_1->getGlobalBounds().width << std::endl;
    //std::cout << TANK_1->getGlobalBounds().height << std::endl;
    ///---

    ///gameloop
    while(window.isOpen()){
        //cmd(): eventos o comandos (dato de entrada)
        //update(): donde procesa la info (proceso)
        //draw(): dibujado de lo que procesó (dato de salida)
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); //borra el dibujo anterior

        //--
        window.draw(*TANK_1);

        //--

        window.display(); //muestra en pantalla
    }
    ///liberación
    return 0;
}
