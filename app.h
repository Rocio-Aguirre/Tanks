#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "bullet.h"
#include "tanque.h"
#include "TileMap.h"
#include "object.h"

class app{
private:

    sf::RenderWindow * ventana1;

    int fps;

    sf::Texture * texture_;
    sf::Sprite * sprite_;

public:

    app();
    app(int resolucion_x, int resolucion_y, std::string titulo);

    void dibujar();

    void checkColission();

    void gameloop();

    sf::RenderWindow * getWindow(){return ventana1;}
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

    Tanque t1(1);
    Tanque t2(2);

    ///Bullet bullet;

    TileMap mapa;


    ///map.load("recursos/graphics.png", sf::Vector2u(16, 16), LVL_2, 26, 26);

    while(ventana1->isOpen()){
        sf::Event event;
        while (ventana1->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                ventana1->close();
        }

        t1.cmd();
        t1.update();

        t2.cmd();
        t2.update();

        //bullet.update();

        //dibujar();

        ventana1->clear();

        /// CHECK COLISSION

                if(t1.getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
                    t1.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t2.getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
                    t2.quieto(t2.getPos_ant().x,t2.getPos_ant().y);
                }

                if(t1.getTankBullet().getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
                    t2.respawn();
                }

                if(t2.getTankBullet2().getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
                    t1.respawn();
                }


        /// -------------

        ventana1->draw(t1.getDraw());
        ventana1->draw(t2.getDraw());
        ventana1->draw(t1.getBulletDraw());
        ventana1->draw(t2.getBulletDraw());
        //ventana1->draw(obj.getDraw());
        mapa.cargar_mapa(*ventana1);

        ventana1->display();


    }
}


#endif // APP_H_INCLUDED
