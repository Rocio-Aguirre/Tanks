#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "app.h"
#include "spriteconfig.h"
#include "gameplay.h"

using namespace std;

class object{
private:
    SpriteType st_type;

    const SpriteData* sd_sprite;

    SpriteConfig * config = new SpriteConfig();

    sf::Sprite s_sprite;

    double pos_x;
    double pos_y;

    int rect_x;
    int rect_y;
    int rect_h;
    int rect_w;

public:
    object();
    ~object();

    /// crea el objeto con el nombre del sprite dado
    object(double x, double y, SpriteType s_type);

    sf::Sprite& getDraw();

    void update();

    const SpriteData * getObjData(){return sd_sprite;}

    ///sf::FloatRect getBounds() const override;
};

object::object(){

    st_type = ST_NONE;

}
object::~object(){
    delete sd_sprite;
    delete config;
}

object::object(double x, double y, SpriteType s_type){

    SpriteConfig config;

    s_sprite.setTexture(*config.getTexture());

    /// establece donde colocar el objeto

    pos_x = x;
    pos_y = y;

    /// obtenemos los datos del sprite
    sd_sprite = SpriteConfig().getData(s_type);

    s_sprite.setTextureRect(sf::IntRect(sd_sprite->x,sd_sprite->y,sd_sprite->h,sd_sprite->w));

    s_sprite.setPosition(pos_x,pos_y);

    ///window.draw(s_sprite);
}

sf::Sprite& object::getDraw(){

    s_sprite.setTextureRect(sf::IntRect(sd_sprite->x,sd_sprite->y,sd_sprite->h,sd_sprite->w));

    s_sprite.setPosition(pos_x,pos_y);
    return s_sprite;
}

/*sf::FloatRect object::getBounds() const override{
    eturn s_sprite.getGlobalBounds();
}*/
#endif // OBJECT_H_INCLUDED
