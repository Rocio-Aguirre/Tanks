#ifndef TANQUE_H_INCLUDED
#define TANQUE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "object.h"

class Tanque{
private:
    //sf::CircleShape _tank;

    ESTADOS_TANQUE _estado;
    ESTADOS_TANQUE _mirando;

    sf::Texture _texture;
    sf::Sprite _tank;
    sf::Sprite _null;

    Bullet _bullet;
    Bullet _bullet2;

    object * obj;

    int player;

    int vida;

    sf::Vector2i pos_ant;

public:
    Tanque(int player);

    void setPlayer(int p){this->player=p;}

    object * getTankObject(){return obj;}
    sf::Vector2i getPos_ant(){return pos_ant;}

    void cmd();
    void update();

    //sf::CircleShape& getDraw();

    void respawn();

    void quieto(float x, float y);

    sf::Texture& getTexture();
    sf::Sprite& getDraw();
    sf::FloatRect getBounds() const;
    sf::Sprite getBulletDraw();

    Bullet getTankBullet(){return _bullet;}
    Bullet getTankBullet2(){return _bullet2;}

};

//////////////////////////////////////////////////////////////////////

Tanque::Tanque(int player){

    this->player = player;

    vida = 4;

        if(player==1){
        _tank.setPosition(20,20);
        }
        else {
            _tank.setPosition(208,352);
        }

    _estado = QUIETO;
    _texture.loadFromFile("resources/400.png");
    _tank.setTexture(_texture);

    ///_tank.setScale(0.5,0.52);

        if(player==1){
            sf::IntRect posicion(4,240,22,32);
            _tank.setTextureRect(posicion);
        }
        else{
            sf::IntRect posicion(4,282,22,32);
            _tank.setTextureRect(posicion);
        }

    _null.setTexture(_texture);
    sf::IntRect posicion2(0,0,4,4);
    _null.setTextureRect(posicion2);

    _tank.setOrigin(_tank.getLocalBounds().width/2,_tank.getLocalBounds().height/2);
    ///cada cuadradito se llama frame
}

/*Tanque::Tanque(int player){
    setPlayer(player);
    obj = new object(0,0,ST_YELLOW_TANK);
}*/

void Tanque::cmd(){

    if(player==1){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                _estado = CAMINANDO_ADELANTE;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                _estado = CAMINANDO_ATRAS;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                _estado = CAMINANDO_ARRIBA;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            _estado = CAMINANDO_ABAJO;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            _bullet.setDisparando(_tank.getPosition().x,_tank.getPosition().y, _mirando);

        }
    }

    if(player==2){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                _estado = CAMINANDO_ADELANTE;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                _estado = CAMINANDO_ATRAS;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                _estado = CAMINANDO_ARRIBA;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            _estado = CAMINANDO_ABAJO;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            _bullet2.setDisparando(_tank.getPosition().x,_tank.getPosition().y, _mirando);
        }
    }
}

void Tanque::update(){

    _bullet.update();
    _bullet2.update();

    pos_ant.x = _tank.getPosition().x;
    pos_ant.y = _tank.getPosition().y;

    switch(_estado){
    case QUIETO:
        break;
    case CAMINANDO_ADELANTE:
        _tank.setRotation(90);
        _tank.move(1,0);

        _mirando = MIRANDO_ADELANTE;
        _estado = QUIETO;
        break;
    case CAMINANDO_ATRAS:
        _tank.setRotation(-90);
        _tank.move(-1,0);

        _mirando = MIRANDO_ATRAS;
        _estado = QUIETO;
        break;
    case CAMINANDO_ARRIBA:
        _tank.setRotation(0);
        _tank.move(0,-1);

        _mirando = MIRANDO_ARRIBA;
        _estado = QUIETO;
        break;
    case CAMINANDO_ABAJO:
        _tank.setRotation(180);
        _tank.move(0,1);

        _mirando = MIRANDO_ABAJO;
        _estado = QUIETO;
    default:
        break;
    }

    /*if(_bullet.getDisparando() == true){
        std::cout << "disparooooo" << std::endl;
        _bullet.getDraw();
        _bullet.setDisparando(false);
    }*/
}
/*
sf::CircleShape& Tanque::getDraw(){
    return _tank;
}
*/
sf::Sprite& Tanque::getDraw(){
    return _tank;
}

sf::Texture& Tanque::getTexture(){
    return _texture;
}

void Tanque::quieto(float x, float y){
    _estado = QUIETO;
    _tank.setPosition(x,y);
}

/*sf::FloatRect Tanque::getBounds() const override{
    return _tank.getGlobalBounds();
}*/

sf::Sprite Tanque::getBulletDraw(){
    if(player==1){
        return _bullet.getDraw();
    }
    else if(player==2){
        return _bullet2.getDraw();
    }
    return _null;

}

void Tanque::respawn(){
    int pos = rand() % 4;

        switch(pos){
    case 0: vida--;
            _tank.setPosition(20,20);

        break;
    case 1: vida--;
            _tank.setPosition(400,20);
        break;
    case 2: vida--;
            _tank.setPosition(20,400);
        break;
    case 3: vida--;
            _tank.setPosition(400,400);
        break;

        }
}


#endif // TANQUE_H_INCLUDED
