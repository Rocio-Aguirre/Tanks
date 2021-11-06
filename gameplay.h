#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

#include "tanque.h"
#include "bloque.h"
#include "object.h"

class Gameplay{
private:
    Tanque tan;
    Bloque b;
    object ob;
public:
    void cmd();
    void update();
    void draw(sf::RenderWindow &);
    /// - Pruebas

    /// -
    void checkCollision();
};

void Gameplay::cmd(){
    tan.cmd();
    b.cmd();
}

void Gameplay::update(){
    tan.update();
    /*if(tan.getDraw().getPosition().y > 500){
        tan.quieto(tan.getDraw().getPosition().x, 500);
    }*/
    b.update();
    checkCollision();
}

void Gameplay::draw(sf::RenderWindow & window){
    window.draw(tan.getDraw());
    window.draw(b.getDraw());
}



void Gameplay::checkCollision(){
    /*if(tan.getDraw().getGlobalBounds().intersects(b.getDraw().getGlobalBounds())){
        tan.quieto(tan.getDraw().getPosition().x, tan.getDraw().getPosition().y);
    }*/
}

#endif // GAMEPLAY_H_INCLUDED
