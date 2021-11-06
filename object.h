#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "spriteconfig.h"

using namespace std;

class object{
private:
    SpriteType ob_type;

    const SpriteData* ob_sprite;

    sf::Sprite * sp_sprite;

    double pos_x;
    double pos_y;

    int rect_x;
    int rect_y;
    int rect_h;
    int rect_w;

public:
    /// incia todo en 0
    object();
    /// crea el objeto con el sprite dado
    // hacer una clase o forma para almacenar sprites
    object(double x, double y, SpriteType s_type);

    void draw();

    void update();
};

object::object(){

    ob_type = ST_NONE;

}

object::object(double x, double y, SpriteType s_type){
    sf::Texture * texture;
    texture->loadFromFile("resources/textures.png");
    /// establece donde colocar el objeto

    pos_x = x;
    pos_y = y;

    /// obtenemos los datos del sprite dado por parametro

    ob_type = s_type;
    ob_sprite = SpriteConfig().getData(s_type);
    rect_x = SpriteConfig().getData(s_type)->d_sprite->getGlobalBounds().top;
    rect_y = SpriteConfig().getData(s_type)->d_sprite->getGlobalBounds().left;
    rect_w = SpriteConfig().getData(s_type)->d_sprite->getGlobalBounds().width;
    rect_h = SpriteConfig().getData(s_type)->d_sprite->getGlobalBounds().height;

    sp_sprite = new sf::Sprite(*texture,sf::IntRect(rect_x,rect_y,rect_w,rect_h));
}

void object::draw(){
    //if(ob_type==ST_NONE) return;
    //else{
    //}
}
#endif // OBJECT_H_INCLUDED
