#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "tanque.h"
#include "TileMap.h"
#include "object.h"
#include "gameplay.h"

class app{
private:
    sf::RenderWindow * ventana1;
    int fps;
    sf::Texture * texture_;
    sf::Sprite * sprite_;
public:
    app(int resolucion_x, int resolucion_y, std::string titulo);
    void dibujar();
    void gameloop();
};

app::app(int resolucion_x, int resolucion_y, std::string titulo){

    fps = 60;

    ventana1 = new sf::RenderWindow(sf::VideoMode(resolucion_x, resolucion_y), titulo);
    ventana1->setFramerateLimit(fps);

    gameloop();
}

void app::dibujar(){

    ventana1->clear();
    ventana1->draw(*sprite_);
    ventana1->display();
}

void app::gameloop(){
    Gameplay g;

    Tanque t;

    TileMap mapa;


    ///map.load("recursos/graphics.png", sf::Vector2u(16, 16), LVL_2, 26, 26);

    while(ventana1->isOpen()){
        sf::Event event;
        while (ventana1->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                ventana1->close();
        }

        t.cmd();
        t.update();
        //dibujar();
        ventana1->clear();
            /*if(t.getBounds().intersects(mapa.getMapObject()->getBounds().)){
                std::cout << " ALTO!" << std::endl;
            }*/

        ventana1->draw(t.getDraw());
        //ventana1->draw(obj.getDraw());
        mapa.cargar_mapa(*ventana1);
        ventana1->display();


    }
}


#endif // APP_H_INCLUDED
