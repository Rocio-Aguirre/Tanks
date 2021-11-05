#ifndef BLOQUE_H_INCLUDED
#define BLOQUE_H_INCLUDED

class Bloque{
private:
    sf::RectangleShape _block;

public:
    void cmd();
    void update();
    sf::RectangleShape& getDraw();
    Bloque();
};

void Bloque::cmd(){

}

void Bloque::update(){

}

sf::RectangleShape& Bloque::getDraw(){
    return _block;
}

Bloque::Bloque(){
    _block.setPosition(300,400);
    _block.setSize({150,40});
}

#endif // BLOQUE_H_INCLUDED
