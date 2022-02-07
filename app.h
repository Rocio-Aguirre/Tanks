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

    Tank * tank1;
    Tank * tank2;

    sf::Texture *_texture;
    sf::Texture *_texture1;
    sf::Sprite *_background;
    sf::Sprite _tank1LifeSprite;
    sf::Sprite _tank2LifeSprite;

    Bonus *_bonus;

    bool check;

    Menu *_menu;
    Menu *_menuLevels;
    Menu *_menuScores;
    bool _entrarMenu;

    int contador;
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

    void mostrarScore();

    void levelMenu();
};

void app::levelMenu(){
    sf::Event event;
    switch(event.type){
        case sf::Event::KeyReleased:
            switch(event.key.code){
                case sf::Keyboard::Up:
                    _menu->moveUp();
                    std::cout << "UP";
                    std::cout << _menu->getPressedItem() << std::endl;
                    break;
                case sf::Keyboard::Down:
                    _menu->moveDown();
                    std::cout << "DOWN";
                    std::cout << _menu->getPressedItem() << std::endl;
                    break;
                    case sf::Keyboard::Return:
                        switch(_menu->getPressedItem()){
                            case 0:
                                std::cout << " asd";
                                    Levels level;
                                    level.getLevel();
                                    tank1 = new Tank(1);
                                    tank2 = new Tank(2);
                                break;
                            case 1:
                                std::cout << " asd3223";
                                break;
                            case 2:
                                std::cout << " asd232332";
                                break;
                            case 3:
                                _ventana1->close();
                                break;
                            default:
                                break;
                        }

                default:
                    break;
            }
    }

}

void app::checkCollisions(Tank &t1, Tank &t2, TileMap &mapa, Bonus &b){
/// CHECK COLISSION

        /// BONUS
            if(_bonus!=NULL){
                if(t1.getDraw().getGlobalBounds().intersects(b.draw().getGlobalBounds())){
                        delete _bonus;
                        _bonus = NULL;
                        t1.addPoints(b.getPoints());

                    }
                if(t2.getDraw().getGlobalBounds().intersects(b.draw().getGlobalBounds())){
                         delete _bonus;
                        _bonus = NULL;
                        t2.addPoints(b.getPoints());
                    }
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
                if(t1.getBulletDraw().getPosition().x > resolucion.x - 128){
                    t1.deleteBullet();
                }
            }

            if(t2.bulletNULL()==false){
                if(t2.getBulletDraw().getPosition().x > resolucion.x - 128){
                    t2.deleteBullet();
                }
            }


        /// ENTRE TANQUES

                if(t1.getDraw().getGlobalBounds().intersects(t2.getDraw().getGlobalBounds())){
                    t1.quieto(t1.getPosAnt().x,t1.getPosAnt().y);
                    t2.quieto(t2.getPosAnt().x,t2.getPosAnt().y);
                }

            /// COLISION DE LA BALA CON EL TANQUE ADVERSARIO

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

                    /// BALA CON EL MAPA
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

                    /// TANQUES CON EL MAPA
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

    /// TEXTURAS Y SPRITES DE LAS VIDAS DE LOS TANQUES
    _texture1 = new sf::Texture;
    _texture1->loadFromFile("resources/400.png");
    _tank1LifeSprite.setTexture(*_texture1);
    _tank1LifeSprite.setPosition(10,40);

    _tank2LifeSprite.setTexture(*_texture1);
    _tank2LifeSprite.setPosition(575,40);


    resolucion.x=resolucion_x;
    resolucion.y=resolucion_y;

    _fps = 60;

    _ventana1 = new sf::RenderWindow(sf::VideoMode(resolucion_x, resolucion_y), titulo);
    _ventana1->setFramerateLimit(_fps);

    gameloop();

    contador=0;
}

bool app::jugar(sf::RenderWindow &window, int level, TileMap &mapa,Tank &tank1,Tank &tank2,Bonus &b){

    checkCollisions(tank1,tank2,mapa,b);

    tank1.update(window);

    tank2.update(window);

    window.draw(tank1.getDraw());
    window.draw(tank2.getDraw());

    /// DIBUJA INTERFAZ DEL JUEGO
        window.draw(*_background);

    /// PONER EL DIBUJADO DE LA VIDA EN UNA FUNCION?
    switch(tank1.getLife()){
        case 1: _tank1LifeSprite.setTextureRect(sf::IntRect(312,44,86,12));
            break;
        case 2: _tank1LifeSprite.setTextureRect(sf::IntRect(312,30,86,12));
            break;
        case 3: _tank1LifeSprite.setTextureRect(sf::IntRect(312,16,86,12));
            break;
        case 4: _tank1LifeSprite.setTextureRect(sf::IntRect(312,2,86,12));
            break;
    }
    switch(tank2.getLife()){
        case 1: _tank2LifeSprite.setTextureRect(sf::IntRect(312,124,86,12));
            break;
        case 2: _tank2LifeSprite.setTextureRect(sf::IntRect(312,110,86,12));
            break;
        case 3: _tank2LifeSprite.setTextureRect(sf::IntRect(312,96,86,12));
            break;
        case 4: _tank2LifeSprite.setTextureRect(sf::IntRect(312,82,86,12));
            break;
    }
    window.draw(_tank1LifeSprite);
    window.draw(_tank2LifeSprite);

    if(_bonus==NULL){
        contador++;
        if(contador>=280){
            _bonus = new Bonus;
            contador=0;
        }
    }

    mapa.mostrarMapa(window);

    if(tank1.getLife() == 0 || tank2.getLife() == 0){
        if(tank1.getPoints()>tank2.getPoints()){
            Tank aux(4);
            aux.addPoints(tank1.getPoints());
            aux.grabarDisco();
        }
        return true;
    }
    return false;
}

void app::mostrarScore(){
    Tank aux(3);
    int pos=0;
    while(aux.leerDisco(pos)){
        aux.mostrar();
        system("pause");
        pos++;
    }
}

void app::gameloop(){

    int opc;
    bool _entrarMenu = true;
    int width = resolucion.x;
    int heigth = resolucion.y;

    _menu = new Menu(width,heigth, 1);


    _bonus = new Bonus;

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
                        if(_entrarMenu==true){
                            switch(_menu->getPressedItem()){
                            case 0: /// JUGAR
                                    _entrarMenu = false;
                                    tank1 = new Tank(1);
                                    tank2 = new Tank(2);
                                break;
                            case 1: /// ELECCION DE NIVEL
                                    ///mapa.setLevel(1);
                                    delete _menu;
                                    _menuLevels = new Menu(width, heigth, 2);

                                        switch(_menuLevels->getPressedItem()){
                                        case 0:
                                            std::cout << "hola soy mapa 1" <<std::endl;
                                            break;
                                        case 1:
                                            std::cout << "hola soy mapa 2" << std::endl;
                                            break;
                                        default:
                                            break;
                                        }

//                                     delete _menu;
//                                    opc=1;
//                                    _menu = new Menu(width,heigth, 2);
//                                    levelMenu();
//                                    _entrarMenu = false;
                                break;
                            case 2: /// MOSTRAR SCORES
                                    delete _menu;
                                    _menuScores = new Menu(width, heigth, 3);

                                break;
                            case 3: /// CERRAR VENTANA
                                _ventana1->close();
                                break;
                            default:
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
        if(_bonus != NULL){_bonus->drawBonus(*_ventana1);}

        _entrarMenu=jugar(*_ventana1,opc,mapa,*tank1,*tank2,*_bonus);
        }
        _ventana1->display();
    }
}

#endif // APP_H_INCLUDED
