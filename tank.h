#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED

class Tank{
private:
    ESTADOS_TANQUE _estado;
    ESTADOS_TANQUE _mirando;

    sf::Texture *_texture;
    sf::Sprite *_sprite;

    Bullet *_bullet;

    int _player;

    int _life;
    sf::Sprite _lifeSprite;

    int points;

    int ShotTime;
    bool Shot;

    sf::Vector2i _posAnt;
public:
    Tank(int player);
    ~Tank();

    void cmd();
    void update(sf::RenderWindow &window);

    void respawn();

    void quieto(float x, float y);

    sf::Vector2i getPosAnt(){return _posAnt;}
    sf::Sprite getDraw();
    sf::Sprite getBulletDraw();
    Bullet getTankBullet(){return *_bullet;}
    int getPoints(){return points;}

    void setPlayer(int p){_player=p;}

    void addPoints(int p){points += p;}

    void deleteBullet(){delete _bullet; _bullet = NULL;}

    bool bulletNULL();

};

//////////////////////////////////////////////////////////////////////

Tank::Tank(int player){

    _texture = new sf::Texture;
    _sprite = new sf::Sprite;

    _player = player;

    _life = 4;

    points=0;

        if(_player==1){
        _sprite->setPosition(145,50);
        }
        else{
            _sprite->setPosition(208,352);
        }

    _estado = QUIETO;
    _texture->loadFromFile("resources/400.png");
    _sprite->setTexture(*_texture);

    _lifeSprite.setTexture(*_texture);


        if(player==1){
            sf::IntRect posicion(4,240,22,32);
            _sprite->setTextureRect(posicion);
        }
        else{
            sf::IntRect posicion(4,282,22,32);
            _sprite->setTextureRect(posicion);
        }

    _sprite->setOrigin(_sprite->getLocalBounds().width/2,_sprite->getLocalBounds().height/2);

    _bullet = NULL;

    ShotTime=0;
    Shot=true;
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

            if(Shot == true){
                _bullet = new Bullet;
                _bullet->setDisparando(_sprite->getPosition().x,_sprite->getPosition().y, _mirando);
                _bullet->setEstado(0);
                _bullet->update();
                ShotTime = 0;
                Shot=false;
            }
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
            if(Shot == true){
                _bullet = new Bullet;
                _bullet->setDisparando(_sprite->getPosition().x,_sprite->getPosition().y, _mirando);
                _bullet->setEstado(0);
                _bullet->update();
                ShotTime = 0;
                Shot=false;
            }
        }
    }
}

bool Tank::bulletNULL(){
    if(_bullet != NULL){
        return false;
    }
    else{
        return true;
    }
}

void Tank::update(sf::RenderWindow &window){

    cmd();

    ShotTime++;

    if(ShotTime == 140){
        Shot = true;
    }

    if(_bullet != NULL){
        _bullet->update();
        _bullet->getDraw(window);
    }

    switch(_life){
    case 1:
            _lifeSprite.setTextureRect(sf::IntRect(312,278,86,12));
        break;
    case 2:
            _lifeSprite.setTextureRect(sf::IntRect(312,264,86,12));
        break;
    case 3:
            _lifeSprite.setTextureRect(sf::IntRect(312,250,86,12));
            _lifeSprite.setPosition(4,59);
        break;
    case 4:
            _lifeSprite.setTextureRect(sf::IntRect(312,236,86,12));
            _lifeSprite.setPosition(4,41);
        break;
    default:
        break;
    }

    window.draw(_lifeSprite);
    _lifeSprite.setColor(sf::Color::Transparent);


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

sf::Sprite Tank::getBulletDraw(){
    return _bullet->getDraw();
}

void Tank::quieto(float x, float y){
    _estado = QUIETO;
    _sprite->setPosition(x,y);
}

void Tank::respawn(){
    int pos = rand() % 4;

        switch(pos){
    case 0: _life--;
            _sprite->setPosition(145,50);
        break;
    case 1: _life--;
            _sprite->setPosition(525,50);
        break;
    case 2: _life--;
            _sprite->setPosition(524,427);
        break;
    case 3: _life--;
            _sprite->setPosition(144,428);
        break;
        }
}

#endif // TANK_H_INCLUDED
