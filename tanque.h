#ifndef TANQUE_H_INCLUDED
#define TANQUE_H_INCLUDED

enum ESTADOS_TANQUE {
        QUIETO,
        CAMINANDO_ADELANTE,
        CAMINANDO_ATRAS,
        CAMINANDO_ARRIBA,
        CAMINANDO_ABAJO
};

class Tanque{
private:
    //sf::CircleShape _tank;
    ESTADOS_TANQUE _estado;
    sf::Texture _texture;
    sf::Sprite _tank;
public:
    void cmd();
    void update();
    //sf::CircleShape& getDraw();
    Tanque();
    void quieto(float x, float y);
    sf::Texture& getTexture();
    sf::Sprite& getDraw();
};


void Tanque::cmd(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                _estado = ESTADOS_TANQUE::CAMINANDO_ADELANTE;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                _estado = ESTADOS_TANQUE::CAMINANDO_ATRAS;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                _estado = ESTADOS_TANQUE::CAMINANDO_ARRIBA;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            _estado = ESTADOS_TANQUE::CAMINANDO_ABAJO;
        }
}

void Tanque::update(){
    switch(_estado){
    case QUIETO:
        break;
    case CAMINANDO_ADELANTE:
        _tank.move(2,0);
        _estado = ESTADOS_TANQUE::QUIETO;
        break;
    case CAMINANDO_ATRAS:
        _tank.move(-2,0);
        _estado = ESTADOS_TANQUE::QUIETO;
        break;
    case CAMINANDO_ARRIBA:
        _tank.move(0,-2);
        _estado = ESTADOS_TANQUE::QUIETO;
        break;
    case CAMINANDO_ABAJO:
        _tank.move(0,2);
        _estado = ESTADOS_TANQUE::QUIETO;
    default:
        break;
    }
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
    //_tank.setFillColor(sf::Color::Green);
    //_tank.setRadius(30);
    _tank.setPosition(20,500);
    _estado = ESTADOS_TANQUE::QUIETO;
    _texture.loadFromFile("tanque.jpg");
    _tank.setTexture(_texture);
    _tank.setScale(0.3, 0.3);
}

void Tanque::quieto(float x, float y){
    _estado = ESTADOS_TANQUE::QUIETO;
    _tank.setPosition(x,y);
}

#endif // TANQUE_H_INCLUDED
