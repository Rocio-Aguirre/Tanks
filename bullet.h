#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

class Bullet{
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    bool _disparando;
public:
    void cmd();
    void update();
    Bullet();
    sf::Texture& getTexture();
    sf::Sprite& getDraw();
    void setDisparando(bool e);
    bool getDisparando();
};

sf::Sprite& Bullet::getDraw(){
    return _sprite;
}

sf::Texture& Bullet::getTexture(){
    return _texture;
}
/*
void Bullet::cmd(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            _disparando = true;
    }
}
*/

/*
void Bullet::update(){
    if(_disparando == true){
        _sprite.getDraw();
    }
}
*/


Bullet::Bullet(){
    std::cout << "holi" << std::endl;
    /*
    _sprite.setPosition(50,450);
    _texture.loadFromFile("tanque.png");
    _sprite.setTexture(_texture);
    _sprite.setScale(5.0, 5.0);
    sf::IntRect posicion(0, 110, 16.66 , 30);
    _sprite.setTextureRect(posicion);
    _sprite.setOrigin(_sprite.getLocalBounds().width/2,_sprite.getLocalBounds().height/2);
    //_disparando = false;
    */
}

void Bullet::setDisparando(bool e){
    _disparando = e;
    _sprite.setPosition(50,450);
    _texture.loadFromFile("tanque.png");
    _sprite.setTexture(_texture);
    _sprite.setScale(5.0, 5.0);
    sf::IntRect posicion(0, 110, 16.66 , 30);
    _sprite.setTextureRect(posicion);
    _sprite.setOrigin(_sprite.getLocalBounds().width/2,_sprite.getLocalBounds().height/2);
}

bool Bullet::getDisparando(){
    return _disparando;
}

#endif // BULLET_H_INCLUDED
