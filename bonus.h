#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

class Bonus{
private:

    sf::Sprite * _sprite;
    sf::Texture * _texture;

    bool _estado; /// TRUE EN MAPA, FALSE BORRADO

    int _points;

public:
    Bonus();

    bonusCreate(int opc, int posX, int posY);

    sf::Sprite draw();

    void objDelete(){delete _sprite; _sprite = NULL; _estado = false;}

    int getPoints(){return _points;}
    bool getEstado(){return _estado;}

    void drawBonus(sf::RenderWindow & window);

};

Bonus::Bonus(){
    _texture = new sf::Texture;
    _texture->loadFromFile("resources/401.png");

    _sprite = new sf::Sprite;
    _sprite->setTexture(*_texture);
    _sprite = new sf::Sprite(*_texture,sf::IntRect(115,76,32,32));
    _sprite->setOrigin(_sprite->getLocalBounds().width/2-5,_sprite->getLocalBounds().height/2);
    _sprite->setPosition(144,428);

    _points = 10;
    _estado = true;
}

sf::Sprite Bonus::draw(){
    return * _sprite;
}

void Bonus::drawBonus(sf::RenderWindow & window){
    window.draw(*_sprite);
}




#endif // BONUS_H_INCLUDED
