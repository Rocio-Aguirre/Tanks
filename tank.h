#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED

class Tank{
private:
    ESTADOS_TANQUE _estado;
    ESTADOS_TANQUE _mirando;

    sf::Texture *_texture;
    sf::Sprite *_sprite;

    Bullet _bullet;

    int _player;

    int _vida;

    sf::Vector2i _posAnt;
public:
    Tank(int player);
    ~Tank();

    void setPlayer(int p){_player=p;}

    sf::Vector2i getPosAnt(){return _posAnt;}

    void cmd();
    void update();

    void respawn();

    void quieto(float x, float y);

    sf::Sprite getDraw();
    sf::Sprite getBulletDraw();

    Bullet getTankBullet(){return _bullet;}

};

//////////////////////////////////////////////////////////////////////

Tank::Tank(int player){

    _texture = new sf::Texture;
    _sprite = new sf::Sprite;

    _player = player;

    _vida = 4;

        if(_player==1){
        _sprite->setPosition(20,20);
        }
        else{
            _sprite->setPosition(208,352);
        }

    _estado = QUIETO;
    _texture->loadFromFile("resources/400.png");
    _sprite->setTexture(*_texture);

        if(player==1){
            sf::IntRect posicion(4,240,22,32);
            _sprite->setTextureRect(posicion);
        }
        else{
            sf::IntRect posicion(4,282,22,32);
            _sprite->setTextureRect(posicion);
        }

    _sprite->setOrigin(_sprite->getLocalBounds().width/2,_sprite->getLocalBounds().height/2);
}

Tank::~Tank(){
    delete _texture;
    delete _sprite;
}

void Tank::cmd(){

    if(_player==1){
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
            _bullet.setDisparando(_sprite->getPosition().x,_sprite->getPosition().y, _mirando);
            _bullet.setEstado(0);

        }
    }

    if(_player==2){
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            _bullet.setDisparando(_sprite->getPosition().x,_sprite->getPosition().y, _mirando);
            _bullet.setEstado(0);
        }
    }
}

void Tank::update(){

    _bullet.update();

    _posAnt.x = _sprite->getPosition().x;
    _posAnt.y = _sprite->getPosition().y;

    switch(_estado){
    case QUIETO:
        break;
    case CAMINANDO_ADELANTE:
        _sprite->setRotation(90);
        _sprite->move(1,0);

        _mirando = MIRANDO_ADELANTE;
        _estado = QUIETO;
        break;
    case CAMINANDO_ATRAS:
        _sprite->setRotation(-90);
        _sprite->move(-1,0);

        _mirando = MIRANDO_ATRAS;
        _estado = QUIETO;
        break;
    case CAMINANDO_ARRIBA:
        _sprite->setRotation(0);
        _sprite->move(0,-1);

        _mirando = MIRANDO_ARRIBA;
        _estado = QUIETO;
        break;
    case CAMINANDO_ABAJO:
        _sprite->setRotation(180);
        _sprite->move(0,1);

        _mirando = MIRANDO_ABAJO;
        _estado = QUIETO;
    default:
        break;
    }

}

sf::Sprite Tank::getDraw(){
    return *_sprite;
}

void Tank::quieto(float x, float y){
    _estado = QUIETO;
    _sprite->setPosition(x,y);
}

sf::Sprite Tank::getBulletDraw(){
    return _bullet.getDraw();
}

void Tank::respawn(){
    int pos = rand() % 4;

        switch(pos){
    case 0: _vida--;
            _sprite->setPosition(20,20);
        break;
    case 1: _vida--;
            _sprite->setPosition(400,20);
        break;
    case 2: _vida--;
            _sprite->setPosition(20,400);
        break;
    case 3: _vida--;
            _sprite->setPosition(400,400);
        break;
        }
}

#endif // TANK_H_INCLUDED
