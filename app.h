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
    mapa.cargar_mapa(*ventana1);

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

            /// TANQUE Y BORDES DEL MAPA

                if(t1.getDraw().getPosition().y > 416 - t1.getDraw().getGlobalBounds().height/2){
                    t1.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t1.getDraw().getPosition().y < 0 + t1.getDraw().getGlobalBounds().height/2){
                    t1.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t1.getDraw().getPosition().x < 0 + t1.getDraw().getGlobalBounds().width/2){
                    t1.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t1.getDraw().getPosition().x > 416 - t1.getDraw().getGlobalBounds().width/2){
                    t1.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }

                if(t2.getDraw().getPosition().y > 416 - t1.getDraw().getGlobalBounds().height/2){
                    t2.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t2.getDraw().getPosition().y < 0 + t1.getDraw().getGlobalBounds().height/2){
                    t2.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t2.getDraw().getPosition().x < 0 + t1.getDraw().getGlobalBounds().width/2){
                    t2.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t2.getDraw().getPosition().x > 416 - t1.getDraw().getGlobalBounds().width/2){
                    t2.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }

            /// ENTRE TANQUES

                if(t1.getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
                    t1.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                }
                if(t2.getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
                    t2.quieto(t2.getPos_ant().x,t2.getPos_ant().y);
                }

                if(t1.getTankBullet().getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
                    t1.getTankBullet().Disparar();
                    t2.respawn();
                }

                if(t2.getTankBullet2().getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
                    t1.respawn();
                }

            /// CON EL MAPA

                for(int x=0; x<26; x++){

                    for(int i=0; i<26; i++){
                        if(t1.getDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
                            t1.quieto(t1.getPos_ant().x,t1.getPos_ant().y);
                        }
                        if(t2.getDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
                            t2.quieto(t2.getPos_ant().x,t2.getPos_ant().y);
                        }
                    }
                }

            /// BALAS CON EL ENTORNO


        /// -------------

        ventana1->draw(t1.getDraw());
        ventana1->draw(t2.getDraw());
        ventana1->draw(t1.getBulletDraw());
        ventana1->draw(t2.getBulletDraw());
        //ventana1->draw(obj.getDraw());
        //mapa.cargar_mapa(*ventana1);
        mapa.mostrar_mapa(*ventana1);

        ventana1->display();


    }
}


#endif // APP_H_INCLUDED
