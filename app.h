#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "menu.h"
#include "bullet.h"
#include "tank.h"
#include "TileMap.h"
#include "bonus.h"

class app{
private:

    sf::RenderWindow *_ventana1;

    int _fps;

    sf::Vector2i resolucion;

    sf::Texture *_texture;
    sf::Texture *_texture1;
    sf::Sprite *_sprite;
    sf::Sprite *_sprite1;

    Menu *_menu;
    bool _entrarMenu;

public:

    app(int resolucion_x, int resolucion_y, std::string titulo);

    void checkCollision();
    void gameloop();

    sf::RenderWindow * getWindow(){return _ventana1;}

    void checkCollisionTwoTanks(Tank &t1, Tank &t2);
    void checkCollisionTankToMap();
    void checkCollisionBulletToTank();
    void checkCollisionBulletToMap();
    void checkCollisions(Tank &t1, Tank &t2, TileMap &mapa, Bonus &b);

    bool jugar(sf::RenderWindow &window, int nivel,TileMap &mapa,Tank &tank1,Tank &tank2,Bonus &b);
};

void app::checkCollisions(Tank &t1, Tank &t2, TileMap &mapa, Bonus &b){
/// CHECK COLISSION

        /// BONUS

            if(t1.getDraw().getGlobalBounds().intersects(b.draw().getGlobalBounds())){
                    t1.addPoints(b.getPoints());

                }
            if(t2.getDraw().getGlobalBounds().intersects(b.draw().getGlobalBounds())){
                    t2.addPoints(b.getPoints());
                }

        /// TANQUE Y BORDES DEL MAPA
            /// ABAJO
            if(t1.getDraw().getPosition().y > resolucion.y - 32 - t1.getDraw().getGlobalBounds().height/2){
                t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }
            /// ARRIBA
            if(t1.getDraw().getPosition().y < 32 + t1.getDraw().getGlobalBounds().height/2){
                t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }
            /// IZQUIERDA
            if(t1.getDraw().getPosition().x < 128 + t1.getDraw().getGlobalBounds().width/2){
                t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }
            /// DERECHA
            if(t1.getDraw().getPosition().x > resolucion.x - 128 - t1.getDraw().getGlobalBounds().width/2){
                t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }

            if(t2.getDraw().getPosition().y > resolucion.y - 32 - t2.getDraw().getGlobalBounds().height/2){
                t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }
            if(t2.getDraw().getPosition().y < 32 + t2.getDraw().getGlobalBounds().height/2){
                t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }
            if(t2.getDraw().getPosition().x < 128 + t2.getDraw().getGlobalBounds().width/2){
                t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }
            if(t2.getDraw().getPosition().x > resolucion.x - 128 - t2.getDraw().getGlobalBounds().width/2){
                t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
            }

            if(t1.bulletNULL()==false){
//                if(t1.getBulletDraw().getPosition().x < 128){
//                    t1.deleteBullet();
//                } EL LADO IZQUIERDO ESTA CAUSANDO PROBLEMAS
                if(t1.getBulletDraw().getPosition().x > resolucion.x - 128){
                    t1.deleteBullet();
                }
            }

            if(t2.bulletNULL()==false){
//                if(t2.getBulletDraw().getPosition().x < 128){
//                    t2.deleteBullet();
//                } EL LADO IZQUIERDO ESTA CAUSANDO PROBLEMAS
                if(t2.getBulletDraw().getPosition().x > resolucion.x - 128){
                    t2.deleteBullet();
                }
            }


        /// ENTRE TANQUES

                if(t1.getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                    t2.quieto(t2.getPosAnt().x,t2.getPosAnt().y);
                }

            /// SI COLISIONA LA BALA CON EL TANQUE ADVERSARIO

                if(t1.bulletNULL() == false){
                    if(t1.getBulletDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
                        t1.deleteBullet();
                        t2.respawn();
                    }
                }

                if(t2.bulletNULL() == false){
                    if(t2.getBulletDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
                        t2.deleteBullet();
                        t1.respawn();
                    }
                }

        /// CON EL MAPA

            for(int x=0; x<26; x++){

                for(int i=0; i<26; i++){

                    if(t1.bulletNULL() != 1){
                        if(t1.getBulletDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
                            t1.deleteBullet();
                        }
                    }
                    if(t2.bulletNULL() != 1){
                        if(t2.getBulletDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
                            t2.deleteBullet();
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
}

app::app(int resolucion_x, int resolucion_y, std::string titulo){

    _sprite = new sf::Sprite;
    _texture = new sf::Texture;
    _texture->loadFromFile("resources/background3.png");
    _sprite->setTexture(*_texture);

    resolucion.x=resolucion_x;
    resolucion.y=resolucion_y;

    _fps = 60;

    _ventana1 = new sf::RenderWindow(sf::VideoMode(resolucion_x, resolucion_y), titulo);
    _ventana1->setFramerateLimit(_fps);

    gameloop();
}

bool app::jugar(sf::RenderWindow &window, int level, TileMap &mapa,Tank &tank1,Tank &tank2,Bonus &b){

    checkCollisions(tank1,tank2,mapa,b);

    tank1.update(window);

    tank2.update(window);

    std::cout << tank1.getLife() << std::endl;

    window.draw(tank1.getDraw());
    window.draw(tank2.getDraw());

    window.draw(*_sprite);
    mapa.mostrarMapa(window);

    if(tank1.getLife() == 0 || tank2.getLife() == 0){
        return true;
    }
    return false;
}

void app::gameloop(){

    int opc;
    bool _entrarMenu = true;
    int width = resolucion.x;
    int heigth = resolucion.y;

    _menu = new Menu(width,heigth);

    Tank tank1(1);
    Tank tank2(2);

    Bonus bonus;

    bonus.bonusCreate(1,524,427);

    TileMap mapa;

    while(_ventana1->isOpen()){
        sf::Event event;
        while (_ventana1->pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                _ventana1->close();
                break;
            case sf::Event::KeyReleased:

                if(_entrarMenu==true){
                    switch(event.key.code){
                    case sf::Keyboard::Up:
                        _menu->moveUp();
                        std::cout << "UP";
                        break;
                    case sf::Keyboard::Down:
                        _menu->moveDown();
                        std::cout << "DOWN";
                        break;
                    case sf::Keyboard::Return:
                        switch(_menu->getPressedItem()){
                        case 0:
                            _entrarMenu = false;
                            break;
                        case 1:
                            std::cout << "Acá se elige nivel" << std::endl;
                            opc=1;
                            break;
                        case 2:
                            std::cout << "Score button pressed" << std::endl;
                            break;
                        case 3:
                            _ventana1->close();
                            break;
                        }

                        break;
                    }
                }
                break;
            }
        }

        _ventana1->clear();

        if(_entrarMenu==true){
            _menu->draw(*_ventana1);
        }
        else{
        _ventana1->draw(bonus.draw());

        _entrarMenu=jugar(*_ventana1,opc,mapa,tank1,tank2,bonus);
        }
        _ventana1->display();
    }
}

//void app::gameloop(){
//
//    Tank t2(2);
//    Tank t1(1);
//
//    TileMap mapa;
//
//    while(_ventana1->isOpen()){
//        sf::Event event;
//        while (_ventana1->pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                _ventana1->close();
//        }
//
//        t1.cmd();
//        t1.update();
//
////        t2.cmd();
////        t2.update();
//
//        _ventana1->clear();
//
//        /// CHECK COLISSION
//
//            /// TANQUE Y BORDES DEL MAPA
//
//                if(t1.getDraw().getPosition().y > 416 - t1.getDraw().getGlobalBounds().height/2){
//                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//                if(t1.getDraw().getPosition().y < 0 + t1.getDraw().getGlobalBounds().height/2){
//                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//                if(t1.getDraw().getPosition().x < 0 + t1.getDraw().getGlobalBounds().width/2){
//                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//                if(t1.getDraw().getPosition().x > 416 - t1.getDraw().getGlobalBounds().width/2){
//                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//
//                if(t2.getDraw().getPosition().y > 416 - t1.getDraw().getGlobalBounds().height/2){
//                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//                if(t2.getDraw().getPosition().y < 0 + t1.getDraw().getGlobalBounds().height/2){
//                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//                if(t2.getDraw().getPosition().x < 0 + t1.getDraw().getGlobalBounds().width/2){
//                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//                if(t2.getDraw().getPosition().x > 416 - t1.getDraw().getGlobalBounds().width/2){
//                    t2.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                }
//
//            /// ENTRE TANQUES
//
////                if(t1.getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
////                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
////                }
////                if(t2.getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
////                    t2.quieto(t2.getPosAnt().x,t2.getPosAnt().y);
////                }
//
//                checkCollisionTwoTanks(&t1,&t2);
//                checkCollisionTwoTanks(&t2,&t1);
//
//
//                /// SI COLISIONA LA BALA
//
//                    if(t1.bulletNULL() != 1){
//
////                    if(t1.getTankBullet().getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
////                        t1.deleteBullet();
////                        t2.respawn();
////                    }
//                    }
//
//
////                    if(t2.getTankBullet().getDraw().getGlobalBounds().intersects(t1.getDraw().getGlobalBounds())){
////                        t1.respawn();
////                    }
//
//            /// CON EL MAPA
//
//                for(int x=0; x<26; x++){
//
//                    for(int i=0; i<26; i++){
//
//                        if(t1.bulletNULL() != 1){
//                            if(t1.getBulletDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
//
//                            }
//                        }
//
//                        if(t1.getDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
//                            t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
//                        }
//                        if(t2.getDraw().getGlobalBounds().intersects(mapa.getMapa(x,i).getGlobalBounds())){
//                            t2.quieto(t2.getPosAnt().x,t2.getPosAnt().y);
//                        }
//                    }
//                }
//
//            /// BALAS CON EL ENTORNO
//
//
//        /// -------------
//
//        _ventana1->draw(t1.getDraw());
//        _ventana1->draw(t2.getDraw());
//
//        if(t1.bulletNULL() != 1){
//            _ventana1->draw(t1.getBulletDraw());
//        }
//
////        _ventana1->draw(t2.getBulletDraw());
//
//        mapa.mostrarMapa(*_ventana1);
//
//        _ventana1->display();
//    }
//}


#endif // APP_H_INCLUDED
