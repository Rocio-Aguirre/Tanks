#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED


enum ESTADOS_TANQUE {
        QUIETO,
        CAMINANDO_ADELANTE,
        CAMINANDO_ATRAS,
        CAMINANDO_ARRIBA,
        CAMINANDO_ABAJO,
        MIRANDO_ARRIBA,
        MIRANDO_ABAJO,
        MIRANDO_ADELANTE,
        MIRANDO_ATRAS,
    };

class Bullet{
private:

    sf::Sprite _sprite;

    sf::Texture _texture;

    ESTADOS_TANQUE _estado;

public:

    Bullet();

    void cmd();

    void update();

    void setDisparando(int pos_x, int pos_y, enum ESTADOS_TANQUE &estado);

    sf::Sprite getDraw();
};

sf::Sprite Bullet::getDraw(){
        return _sprite;
}

Bullet::Bullet(){

    _texture.loadFromFile("resources/400.png");
    _sprite.setTexture(_texture);

    sf::IntRect posicion(190,248,15,15);
    _sprite.setTextureRect(posicion);

    _sprite.setOrigin(_sprite.getLocalBounds().width/2,_sprite.getLocalBounds().height/2);

    _sprite.setPosition(900,900);
}

void Bullet::setDisparando(int pos_x, int pos_y, enum ESTADOS_TANQUE &estado){

            switch(estado){
                case MIRANDO_ADELANTE:  _estado=MIRANDO_ADELANTE;
                    break;
                case MIRANDO_ABAJO: _estado=MIRANDO_ABAJO;
                    break;
                case MIRANDO_ARRIBA:    _estado=MIRANDO_ARRIBA;
                    break;
                case MIRANDO_ATRAS: _estado=MIRANDO_ATRAS;
                    break;
                default:
                    break;
                }

            _sprite.setPosition(pos_x,pos_y);
}

void Bullet::update(){

    switch(_estado){
    case MIRANDO_ADELANTE:
            _sprite.setRotation(90);
            _sprite.move(3,0);
        break;
    case MIRANDO_ABAJO:
            _sprite.setRotation(180);
            _sprite.move(0,3);

        break;
    case MIRANDO_ARRIBA:
            _sprite.setRotation(0);
            _sprite.move(0,-3);
        break;
    case MIRANDO_ATRAS:
            _sprite.setRotation(-90);
            _sprite.move(-3,0);
        break;
    default:
        break;
    }

}


#endif // BULLET_H_INCLUDED
