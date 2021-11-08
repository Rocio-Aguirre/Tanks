#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

#include "tanque.h"
#include "bloque.h"

class Gameplay{
private:
    Tanque tan[2];
    Bloque b;
public:
    void cmd();
    void update();
    void draw(sf::RenderWindow &);
    void checkCollision();
};

void Gameplay::cmd(){
    tan[0].cmd();
    tan[1].cmd();
    b.cmd();
}

void Gameplay::update(){
    for(int i=0; i<2;i++){
        tan[i].update();
        if(tan[i].getDraw().getPosition().y > 500){
            tan[i].quieto(tan[i].getDraw().getPosition().x, 500);
        }
    }
        b.update();
        checkCollision();
}

void Gameplay::draw(sf::RenderWindow & window){
    window.draw(tan[0].getDraw());
    window.draw(tan[1].getDraw());
    window.draw(b.getDraw());
}

void Gameplay::checkCollision(){
    for(int i=0; i<2; i++){
        if(tan[i].getDraw().getGlobalBounds().intersects(b.getDraw().getGlobalBounds())){
            tan[i].quieto(tan[i].getDraw().getPosition().x, tan[i].getDraw().getPosition().y);
        }
    }

}

#endif // GAMEPLAY_H_INCLUDED
