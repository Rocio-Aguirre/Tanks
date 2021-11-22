#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "bullet.h"
#include "tank.h"
#include "TileMap.h"

class app{
private:

    sf::RenderWindow *_ventana1;

    int _fps;

    sf::Texture *_texture;
    sf::Sprite *_sprite;

public:

    app(int resolucion_x, int resolucion_y, std::string titulo);

    void checkCollision();
    void gameloop();

    sf::RenderWindow * getWindow(){return _ventana1;}

    void checkCollisionTwoTanks(Tank *t1, Tank *t2);
    void checkCollisionTankToMap();
    void checkCollisionBulletToTank();
    void checkCollisionBulletToMap();
};

void app::checkCollisionTwoTanks(Tank *t1, Tank *t2){

    if(t1->getDraw().getGlobalBounds().intersects(t2->getDraw().getGlobalBounds())){

        t1->quieto(t1->getPosAnt().x,t1->getPosAnt().y);
    }
}

app::app(int resolucion_x, int resolucion_y, std::string titulo){

    _fps = 60;

    _ventana1 = new sf::RenderWindow(sf::VideoMode(resolucion_x, resolucion_y), titulo);
    _ventana1->setFramerateLimit(_fps);

    gameloop();
}

void app::gameloop(){

    Tank t2(2);
    Tank t1(1);

    TileMap mapa;

    while(_ventana1->isOpen()){
        sf::Event event;
        while (_ventana1->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _ventana1->close();
        }

        t1.cmd();
        t1.update();

//        t2.cmd();
//        t2.update();

        _ventana1->clear();

        /// CHECK COLISSION

            /// TANQUE Y BORDES DEL MAPA

                if(t1.getDraw().getPosition().y > 416 - t1.getDraw().getGlobalBounds().height/2){
                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }
                if(t1.getDraw().getPosition().y < 0 + t1.getDraw().getGlobalBounds().height/2){
                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }
                if(t1.getDraw().getPosition().x < 0 + t1.getDraw().getGlobalBounds().width/2){
                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }
                if(t1.getDraw().getPosition().x > 416 - t1.getDraw().getGlobalBounds().width/2){
                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }

                if(t2.getDraw().getPosition().y > 416 - t1.getDraw().getGlobalBounds().height/2){
                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }
                if(t2.getDraw().getPosition().y < 0 + t1.getDraw().getGlobalBounds().height/2){
                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }
                if(t2.getDraw().getPosition().x < 0 + t1.getDraw().getGlobalBounds().width/2){
                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }
                if(t2.getDraw().getPosition().x > 416 - t1.getDraw().getGlobalBounds().width/2){
                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                }

            /// ENTRE TANQUES

//                if(t1.getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
//                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//                if(t2.getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
//                    t2.quieto(t2.getPosAnt().x,t2.getPosAnt().y);
//                }

                checkCollisionTwoTanks(&t1,&t2);
                checkCollisionTwoTanks(&t2,&t1);


                /// SI COLISIONA LA BALA

                    if(t1.bulletNULL() != 1){

//                    if(t1.getTankBullet().getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
//                        t1.deleteBullet();
//                        t2.respawn();
//                    }
                    }


//                    if(t2.getTankBullet().getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
//                        t1.respawn();
//                    }

            /// CON EL MAPA

                for(int x=0; x<26; x++){

                    for(int i=0; i<26; i++){

                        if(t1.bulletNULL() != 1){
                            if(t1.getBulletDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){

                            }
                        }

                        if(t1.getDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
                            t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                        }
                        if(t2.getDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
                            t2.quieto(t2.getPosAnt().x,t2.getPosAnt().y);
                        }
                    }
                }

            /// BALAS CON EL ENTORNO


        /// -------------

        _ventana1->draw(t1.getDraw());
        _ventana1->draw(t2.getDraw());

        if(t1.bulletNULL() != 1){
            _ventana1->draw(t1.getBulletDraw());
        }

//        _ventana1->draw(t2.getBulletDraw());

        mapa.mostrarMapa(*_ventana1);

        _ventana1->display();
    }
}


#endif // APP_H_INCLUDED
