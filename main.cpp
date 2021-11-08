#include <SFML/Graphics.hpp>
#include <iostream>

#include "gameplay.h"
#include "object.h"
#include "spriteconfig.h"

int main()
{
    ///inicialización
    sf::RenderWindow window(sf::VideoMode(800,600), "TANKS!");
    window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    ///---
    object obj;

    SpriteConfig * config = new SpriteConfig();

    sf::Texture * texture = new sf::Texture();
    texture->loadFromFile("resources/textures.png");

    sf::Sprite * TANK_1 = new sf::Sprite(*texture,sf::IntRect(70,5,15,13));

    obj.new_object(3,3,ST_YELLOW_TANK);

    ///
    /*
    /// establece donde colocar el objeto
    const SpriteData* ob_sprite;
    SpriteType s_type=ST_YELLOW_TANK;

    int pos_x = 50;
    int pos_y = 60;

    /// obtenemos los datos del sprite dado por parametro

    ob_sprite = SpriteConfig().getData(s_type);
    int rect_x = SpriteConfig().getData(s_type)->x;
    int rect_y = SpriteConfig().getData(s_type)->y;
    int rect_w = SpriteConfig().getData(s_type)->w;
    int rect_h = SpriteConfig().getData(s_type)->h;
    cout << rect_x << " " << rect_y << " " << rect_w << " " << rect_h << " ";
    sf::Sprite * TANK_1 = new sf::Sprite(*texture,sf::IntRect(rect_x,rect_y,rect_w,rect_h));
    TANK_1->setPosition(80,100);
    */
    ///


    //-- este da error
    ///std::cout << SpriteConfig().getData(ST_RED_BLOCK)->d_sprite->getGlobalBounds().height << std::endl;
    //std::cout << TANK_1->getGlobalBounds().width << std::endl;
    //std::cout << TANK_1->getGlobalBounds().height << std::endl;


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
