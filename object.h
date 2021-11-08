#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "spriteconfig.h"

using namespace std;

class object{
private:
    SpriteType st_type;

    const SpriteData* sd_sprite;

    sf::Sprite * sp_sprite;

    double pos_x;
    double pos_y;

    int rect_x;
    int rect_y;
    int rect_h;
    int rect_w;

public:
    object();
    /// crea el objeto con el nombre del sprite dado
    sf::Sprite * new_object(double x, double y, SpriteType s_type);

    void draw();

    void update();
};

object::object(){

    st_type = ST_NONE;

}

sf::Sprite * object::new_object(double x, double y, SpriteType s_type){
    SpriteConfig config;
    sf::Texture * texture;
    texture->loadFromFile("resources/textures.png");

    /// establece donde colocar el objeto

    pos_x = x;
    pos_y = y;

    /// obtenemos los datos del sprite

    rect_x = SpriteConfig().getData(s_type)->x;
    rect_y = SpriteConfig().getData(s_type)->y;
    rect_w = SpriteConfig().getData(s_type)->w;
    rect_h = SpriteConfig().getData(s_type)->h;

    //sp_sprite = new sf::Sprite(*texture,sf::IntRect(1,1,1,1));
    //sp_sprite->setPosition(80,80);
    cout << rect_x << " " << rect_y << " " << rect_w << " " << rect_h << " ";
    //return sp_sprite;
}

void object::draw(){
    if(st_type==ST_NONE) return;
    else{
            /// Aún no terminado
    }
}
#endif // OBJECT_H_INCLUDED
