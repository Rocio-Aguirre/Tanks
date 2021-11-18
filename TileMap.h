#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED

/*#include "object.h"
#include "app.h"*/

const int LVL_1[] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
        1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,
        1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,
        0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,
        0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,1,0,0,
        0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,

};
const int LVL_2[] =
    {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

};
class TileMap{
private:
    sf::Sprite * map_sprite;
    sf::Texture * texture;

    ///object * mapa[26][26];
    sf::Sprite  * mapa[26][26];

    object * obj;

    int nivel;
    int matriz[26][26];

public:

    TileMap();

    sf::Sprite getMap_sprite(){ return * map_sprite;}

    ///sf::Sprite getVec_Map_sprite(){ return * * * mapa;}

    ///object * getMapa(int x, int i){return  mapa[x][i];}

    sf::Sprite & getMapa(int x, int i){return  * mapa[x][i];}


    void cargar_mapa(sf::RenderWindow & window);

    bool leerDisco(int pos){
        FILE *p;
        bool res;
        p = fopen("interpretes.dir", "rb");
        if(p == NULL) return false;
        fseek(p, pos * sizeof *this, 0);
        res = fread(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }

    ///object * getMapObject(){return obj;}

    void mostrar_mapa(sf::RenderWindow & window);

    bool collision(sf::Sprite sprite);
};

TileMap::TileMap(){

}

void TileMap::cargar_mapa(sf::RenderWindow & window){

    /// void TileMap::cargar_mapa(nivel)

    texture = new sf::Texture();
    texture->loadFromFile("resources/400.png");

    int escala=16;
    for(int x=0;x<26;x++){

        for(int j=0;j<26;j++){

            int actual = LVL_1[x * 26 + j];

            switch(actual){
                case 1:
                    ///if(obj!=NULL)delete obj;
                    ///obj =  new object(j * 16 ,x * 16,ST_RED_BLOCK);
                    ///window.draw(obj->getDraw());

                    /*mapa[x][j] = obj;

                    window.draw(mapa[x][j]->getDraw());*/

                    map_sprite = new sf::Sprite(*texture,sf::IntRect(4,4,16,16));

                    map_sprite->setPosition(j*escala,x*escala);

                    mapa[x][j] = map_sprite;

                    window.draw(*map_sprite);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                default:
                    /*obj =  new object(1,1,ST_NONE);
                    mapa[x][j] = obj;*/

                    map_sprite = new sf::Sprite(*texture,sf::IntRect(0,0,0,0));

                    map_sprite->setPosition(j*escala,x*escala);

                    mapa[x][j] = map_sprite;

                    break;
            }

        }
    }

    ///delete texture;
}

/*void TileMap::mostrar_mapa(sf::RenderWindow & window){

    for(int x=0;x<26;x++){

        for(int j=0;j<26;j++){
                    window.draw(mapa[x][j]->getDraw());
        }
    }
}*/

void TileMap::mostrar_mapa(sf::RenderWindow & window){

    for(int x=0;x<26;x++){

        for(int j=0;j<26;j++){
                    window.draw(*mapa[x][j]);
        }
    }
}

/*bool TileMap::collision(sf::Sprite sprite){
    for(int x=0;x<26;x++){

        for(int j=0;j<26;j++){

                if(sprite.getGlobalBounds().intersects(mapa[x][j]->getDraw().getGlobalBounds())){
                    std::cout << " ajsas ";
                    return true;
                }


        }
    }
    return false;
}*/

bool TileMap::collision(sf::Sprite sprite){
    for(int x=0;x<26;x++){

        for(int j=0;j<26;j++){

                if(sprite.getGlobalBounds().intersects(mapa[x][j]->getGlobalBounds())){
                    std::cout << " ajsas ";
                    return true;
                }


        }
    }
    return false;
}

#endif // TILEMAP_H_INCLUDED
