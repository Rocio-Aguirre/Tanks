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

    ///object  bullet;
    sf::Sprite _sprite;
    sf::Texture _texture;

    sf::Sprite _null;

    bool disparar;

    bool destruir;

    int pos_x, pos_y;

    ESTADOS_TANQUE _estado;

public:

    Bullet();

    void cmd();

    void update();

    void setDisparando(int pos_x, int pos_y, enum ESTADOS_TANQUE &estado);

    void Disparar(){disparar=false;}

    sf::Sprite getDraw();
};

Bullet::Bullet(){
    _texture.loadFromFile("resources/400.png");
    _sprite.setTexture(_texture);
    sf::IntRect posicion(190,248,15,15);
    _sprite.setTextureRect(posicion);
    _sprite.setOrigin(_sprite.getLocalBounds().width/2,_sprite.getLocalBounds().height/2);

    _null.setTexture(_texture);
    sf::IntRect posicion2(0,0,4,4);
    _null.setTextureRect(posicion2);

    disparar = false;
}

void Bullet::setDisparando(int pos_x, int pos_y, enum ESTADOS_TANQUE &estado){

    if(disparar==false){
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

    std::cout << " setdisparando ";

    disparar = true;
    }

}

void Bullet::update(){

    if(disparar==true){
        switch(_estado){
        case MIRANDO_ADELANTE:
            /*bullet = new object(pos_x,pos_y,ST_YELLOW_BULLET);
            bullet.getDraw().setRotation(90);
            bullet.move(3,0);*/
            _sprite.setRotation(90);
            _sprite.move(3,0);

            break;
        case MIRANDO_ABAJO:
            /*bullet = new object(pos_x,pos_y,ST_YELLOW_BULLET);
            bullet.getDraw().setRotation(180);
            bullet.move(0,3);*/
            _sprite.setRotation(180);
            _sprite.move(0,3);

            break;
        case MIRANDO_ARRIBA:
            /*bullet = new object(pos_x,pos_y,ST_YELLOW_BULLET);
            bullet.getDraw().setRotation(0);
            bullet.move(0,-3);*/
            _sprite.setRotation(0);
            _sprite.move(0,-3);
            break;
        case MIRANDO_ATRAS:
            /*bullet = new object(pos_x,pos_y,ST_YELLOW_BULLET);
            bullet.getDraw().setRotation(-90);
            bullet.move(-3,0);*/
            _sprite.setRotation(-90);
            _sprite.move(-3,0);
            break;
        default:
            break;
        }
    }
}

sf::Sprite Bullet::getDraw(){
    if(disparar==true){
        return _sprite;
    }else{
        return _null;
    }


}

#endif // BULLET_H_INCLUDED
