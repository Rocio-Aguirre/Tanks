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
    sf::Sprite *_background;
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

    void setLevel(int lvl, TileMap &mapa);

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

    _background = new sf::Sprite;
    _texture = new sf::Texture;
    _texture->loadFromFile("resources/background3.png");
    _background->setTexture(*_texture);

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

    window.draw(tank1.getDraw());
    window.draw(tank2.getDraw());

    /// DIBUJA INTERFAZ DEL JUEGO
        window.draw(*_background);

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
    setLevel(1, mapa);

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
                        if(_entrarMenu==true){
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

void app::setLevel(int lvl, TileMap &mapa){
    int escala=16;
    int pos=0;

    sf::Sprite * _sprite;

    while(mapa.leerDisco(pos)){
//        std::cout << mapa.getLevel() << " == " << lvl << std::endl;
//        if(mapa.getLevel() == lvl){
//            for(int x=0;x<26;x++){
//                for(int j=0;j<26;j++){
//                    int actual = mapa.getMapDat(x,j);
//                    switch(actual){
//                        case 1:
//                            std::cout << "asda s";
//                            _sprite = new sf::Sprite(*_texture,sf::IntRect(4,4,16,16));
//
//                            _sprite->setPosition(128+j*escala,32+x*escala);
//
//                            /mapa.setMapSprite(_sprite,x,j);
//                            break;
//                        case 2:
//                            break;
//                        case 3:
//                            break;
//                        case 4:
//                            break;
//                        case 5:
//                            break;
//                        case 6:
//                            break;
//                        case 7:
//                            break;
//                        case 8:
//                            break;
//                        case 9:
//                            _sprite = new sf::Sprite(*_texture,sf::IntRect(207,14,16,16));
//
//                            _sprite->setPosition(128+j*escala,32+x*escala);
//
//                            /mapa.setMapSprite(_sprite,x,j);
//                            break;
//                        default:
//                            _sprite = new sf::Sprite(*_texture,sf::IntRect(0,0,0,0));
//
//                            _sprite->setPosition(j*escala,x*escala);
//
//                            /mapa.setMapSprite(_sprite,x,j);
//                            break;
//                    }
//                }
//            }
//
//        }else{
//            std::cout << " NO SE PUDO ENCONTRAR EL MAPA" << std::endl;
//        }
        pos++;
    }
}

#endif // APP_H_INCLUDED
