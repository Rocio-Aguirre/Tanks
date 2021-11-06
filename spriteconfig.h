#ifndef SPRITETYPES_H_INCLUDED
#define SPRITETYPES_H_INCLUDED

#include "gameplay.h"

#include <iostream>
#include <SFML/Graphics.hpp>

enum SpriteType{
    ST_YELLOW_TANK,
    ST_RED_TANK,
    ST_BLUE_TANK,
    ST_GREEN_TANK,
    ST_RED_BLOCK,
    ST_BLUE_BLOCK,
    ST_GREEN_BLOCK,
    ST_YELLOW_BLOCK,
    ST_NONE,
};

struct SpriteData
{
    SpriteData(){
        d_sprite->setTextureRect(sf::IntRect(0,0,0,0));
        }
    SpriteData(int x, int y, int w, int h){
        d_sprite->setTextureRect(sf::IntRect(x,y,w,h));
    }
    sf::Sprite * d_sprite = new sf::Sprite;
};

class SpriteConfig{
private:
    //sf::Texture * texture;
    sf::Sprite * s_sprite;
    std::map<SpriteType, ss_sprite> m_SpriteConfig;

public:
    SpriteConfig();

    /// Funcion que crea Sprites (nombre,x,y,alcho,alto)

    void create(SpriteType sp_type, int x, int y, int w, int h);

    /// Funcion que recibe nombre del sprite y devuelve los valores del sprite (pos x, pos y, ancho, alto)
    const SpriteData* getData(SpriteType st);
};

void SpriteConfig::create(SpriteType sp_type, int x, int y, int w, int h){
    sf::Texture * texture;
    texture->loadFromFile("resources/textures.png");
    sf::Sprite * map_sprite = new sf::Sprite(*texture,sf::IntRect(x,y,w,h));
    m_SpriteConfig[sp_type] = map_sprite;
    //m_SpriteConfig[sp_type] = SpriteData(x,y,w,h);


}

const SpriteData* SpriteConfig::getData(SpriteType st){
    return &m_SpriteConfig.at(st);
}

SpriteConfig::SpriteConfig(){
     /// creamos Sprites (nombre,x,y,alcho,alto)
    create(ST_RED_BLOCK,3,5,15,13);
}
#endif // SPRITETYPES_H_INCLUDED
