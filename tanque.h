#ifndef TANQUE_H_INCLUDED
#define TANQUE_H_INCLUDED

#include <SFML/Graphics.hpp>

class Tanque{
private:
    enum ESTADOS_TANK{
        QUIETO,
        DERECHA,
        IZQUIERDA,
        ABAJO,
        ARRIBA,
        DISPARO,
    };
    sf::RectangleShape _shape;
    sf::Texture * texture_;
    sf::Sprite * sprite_;
    int _estado;
public:

    tank(){

        texture_ = new sf::Texture;
        texture_->loadFromFile("recursos/enemy_a.png");

        ///_shape.setSize(sf::Vector2f(40.f, 40.f));
        ///_shape.setPosition(10,10);
        ///_shape.setTexture(&TANK_A);

        sprite_ = new sf::Sprite(*texture_);

        sprite_->setPosition(200,200);

        sprite_->setOrigin(sprite_->getGlobalBounds().height/2,sprite_->getGlobalBounds().width/2);
    }
    void cmd(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            _estado = DERECHA;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            _estado = IZQUIERDA;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            _estado = ARRIBA;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
           _estado = ABAJO;
        }
    }
    void update(){
        switch(_estado){
    case QUIETO:
        break;
    case DERECHA:
        sprite_->setRotation(90);
        sprite_->move(1,0);
        _estado = QUIETO;
        break;
    case IZQUIERDA:
        sprite_->setRotation(-90);
        sprite_->move(-1,0);
        _estado = QUIETO;
        break;
    case ARRIBA:
        sprite_->setRotation(0);
        sprite_->move(0,-1);
        _estado = QUIETO;
        break;
    case ABAJO:
        sprite_->setRotation(180);
        sprite_->move(0,1);
        _estado = QUIETO;
        break;
    default:
        break;
        }
    }
    sf::Sprite& getDraw(){return * sprite_;}
};
#endif // TANQUE_H_INCLUDED
