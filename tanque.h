#ifndef TANQUE_H_INCLUDED
#define TANQUE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "object.h"

class Tanque :: public Gameplay{
private:
    //sf::CircleShape _tank;
    enum ESTADOS_TANQUE {
        QUIETO,
        CAMINANDO_ADELANTE,
        CAMINANDO_ATRAS,
        CAMINANDO_ARRIBA,
        CAMINANDO_ABAJO,
    };
    ESTADOS_TANQUE _estado;
    ESTADOS_TANQUE _estadoAnterior;
    sf::Texture _texture;
    sf::Sprite _tank;
    ///Bullet _bullet;

public:
    void cmd();
    void update();
    //sf::CircleShape& getDraw();
    Tanque();
    void quieto(float x, float y);
    sf::Texture& getTexture();
    sf::Sprite& getDraw();
    sf::FloatRect getBounds() const;
};

void Tanque::cmd(){
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
            ///_bullet.setDisparando(true);
            ///std::cout << "Disparando: " << _bullet.getDisparando() << std::endl;
        }
}

void Tanque::update(){
    switch(_estado){
    case QUIETO:
        break;
    case CAMINANDO_ADELANTE:
        _tank.setRotation(90);
        _tank.move(1,0);

        _estadoAnterior = _estado;
        _estado = QUIETO;
        break;
    case CAMINANDO_ATRAS:
        _tank.setRotation(-90);
        _tank.move(-1,0);

        _estadoAnterior = _estado;
        _estado = QUIETO;
        break;
    case CAMINANDO_ARRIBA:
        _tank.setRotation(0);
        _tank.move(0,-1);

        _estadoAnterior = _estado;
        _estado = QUIETO;
        break;
    case CAMINANDO_ABAJO:
        _tank.setRotation(180);
        _tank.move(0,1);

        _estadoAnterior = _estado;
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

Tanque::Tanque(){
    _tank.setPosition(10,10);
    _estado = QUIETO;
    _texture.loadFromFile("resources/400.png");
    _tank.setTexture(_texture);
    ///_tank.setScale(0.5,0.52);
    sf::IntRect posicion(4,240,22,32);
    _tank.setTextureRect(posicion);


    _tank.setOrigin(_tank.getLocalBounds().width/2,_tank.getLocalBounds().height/2);
    ///cada cuadradito se llama frame
}

void Tanque::quieto(float x, float y){
    _estado = QUIETO;
    _tank.setPosition(x,y);
}

sf::FloatRect Tanque::getBounds() const override{
    return _tank.getGlobalBounds();
}


#endif // TANQUE_H_INCLUDED
