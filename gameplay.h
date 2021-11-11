#ifndef GAMEPLAY_H_INCLUDED
#define GAMEPLAY_H_INCLUDED

#include "tanque.h"
#include "bloque.h"
#include "object.h"

class Gameplay{
private:
public:
    void cmd();
    void update();
    void draw(sf::RenderWindow &);
    /// - Pruebas

    /// -
    virtual sf::FloatRect getBounds() const = 0;
    bool checkCollision(Gameplay& obj) const;
};

/*void Gameplay::cmd(){
    tan.cmd();
    b.cmd();
}

void Gameplay::update(){
    tan.update();
    /*if(tan.getDraw().getPosition().y > 500){
        tan.quieto(tan.getDraw().getPosition().x, 500);
    }*//*
    b.update();
    checkCollision();
}

void Gameplay::draw(sf::RenderWindow & window){
    window.draw(tan.getDraw());
    window.draw(b.getDraw());
}*/

bool Gameplay::checkCollision(Gameplay& obj) const{
    ///return getBounds().intersects(obj.getBounds()) const;
}

#endif // GAMEPLAY_H_INCLUDED
