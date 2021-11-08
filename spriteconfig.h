#ifndef SPRITETYPES_H_INCLUDED
#define SPRITETYPES_H_INCLUDED

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

class SpriteData{
private:
public:
    int x;
    int y;
    int w;
    int h;
    SpriteData(){
         x=0; y=0; w=0; h=0;
        }
    SpriteData(int x, int y, int w, int h){
        x=x; y=y; w=w; h=h;
    }
    int getX(){return x;}
    int getY(){return y;}
    int getW(){return w;}
    int getH(){return h;}

    void setX(int x){this->x=x;}
    void setY(int y){this->y=y;}
    void setW(int w){this->w=w;}
    void setH(int h){this->h=h;}
};

class SpriteConfig{
private:
    //sf::Texture * texture;
    sf::Sprite * s_sprite;
    std::map<SpriteType, SpriteData> m_SpriteConfig;

public:
    SpriteConfig();

    /// Funcion que crea Sprites (nombre,x,y,alcho,alto)

    void create(SpriteType sp_type, int x, int y, int w, int h);

    /// Funcion que recibe nombre del sprite y devuelve los valores del sprite (pos x, pos y, ancho, alto)
    const SpriteData* getData(SpriteType st);
};

void SpriteConfig::create(SpriteType sp_type, int x, int y, int w, int h){
    SpriteData datos;
        datos.setX(x);
        datos.setY(y);
        datos.setW(w);
        datos.setH(h);
    ///m_SpriteConfig[sp_type] = SpriteData(x,y,w,h);
    m_SpriteConfig[sp_type] = datos;

}

const SpriteData* SpriteConfig::getData(SpriteType st){
    return &m_SpriteConfig.at(st);
}

SpriteConfig::SpriteConfig(){

     /// creamos los Sprites (nombre,x,y,alcho,alto)

    create(ST_RED_BLOCK,3,5,15,13);
    create(ST_YELLOW_TANK,3,208,20,28);
}
#endif // SPRITETYPES_H_INCLUDED