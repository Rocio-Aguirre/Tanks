#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

class Bonus{
private:
    sf::Sprite * _sprite;
    sf::Texture * _texture;

    int points;

public:
    bonus();

    bonusCreate(int opc, int posX, int posY);

    sf::Sprite draw();

    void objDelete();

    int getPoints(){return points;}

};

Bonus::bonusCreate(int opc, int posX, int posY){
    _texture = new sf::Texture;
    _texture->loadFromFile("resources/401.png");

    _sprite = new sf::Sprite;
    _sprite->setTexture(*_texture);
    _sprite = new sf::Sprite(*_texture,sf::IntRect(115,76,32,32));
    _sprite->setOrigin(_sprite->getLocalBounds().width/2-5,_sprite->getLocalBounds().height/2);
    _sprite->setPosition(posX,posY);

    points = 10;
}

sf::Sprite Bonus::draw(){
    return * _sprite;
}




#endif // BONUS_H_INCLUDED
