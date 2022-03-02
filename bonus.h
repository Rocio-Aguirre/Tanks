#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED

class Bonus{
private:

    sf::Sprite * _sprite;
    sf::Texture * _texture;

    int _points;

public:
    Bonus();

    void bonusCreate();

    sf::Sprite draw();

    void objDelete(){delete _sprite; _sprite = NULL;}

    int getPoints(){return _points;}

    void drawBonus(sf::RenderWindow & window);

    void respawn();

};

Bonus::Bonus(){
    _texture = new sf::Texture;
    _texture->loadFromFile("resources/401.png");

    _sprite = new sf::Sprite;
    _sprite->setTexture(*_texture);
    _sprite = new sf::Sprite(*_texture,sf::IntRect(115,76,32,32));
    _sprite->setOrigin(_sprite->getLocalBounds().width/2-5,_sprite->getLocalBounds().height/2);

    /// GENERAR EL BONUS EN UNA POSICION RANDOM
    respawn();

    _points = 100;
}

void Bonus::respawn(){
    int pos = rand() % 4;

        switch(pos){
            case 0:
                    _sprite->setPosition(145,50);
                break;
            case 1:
                    _sprite->setPosition(525,50);
                break;
            case 2:
                    _sprite->setPosition(524,427);
                break;
            case 3:
                    _sprite->setPosition(144,428);
            break;
        }
}

void Bonus::bonusCreate(){

}

sf::Sprite Bonus::draw(){
    return * _sprite;
}

void Bonus::drawBonus(sf::RenderWindow & window){
    window.draw(*_sprite);
}

#endif // BONUS_H_INCLUDED
