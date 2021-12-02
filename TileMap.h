#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED

#include <iostream>

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
        0,0,0,0,0,0,0,0,0,0,0,1,9,9,1,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,1,9,9,1,0,0,0,0,0,0,0,0,0,0,0,

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
    sf::Sprite *_sprite;
    sf::Texture *_texture;
    sf::Sprite  *_mapa[26][26];

    int _level;
    int _mapDat[26][26];
public:

    TileMap();
    ~TileMap();

    sf::Sprite getMapSprite(){ return *_sprite;}

    sf::Sprite getMapa(int x, int i){return  *_mapa[x][i];}
    sf::Sprite &getMapaB(){return  **_mapa[26];}
    int getLevel(){return _level;}
    int getMapDat(int x, int y){return _mapDat[x][y];}

    bool grabarDisco(){
        FILE *p;
        bool res;
        p = fopen("mapas.dat", "ab");
        if(p == NULL) return false;
        res = fwrite(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }

    void ingresarMapa(){
        std::cout << "NIVEL: ";

        std::cin >> _level;

        int cas;

        for(int line=0;line<13;line++){
            std::cout << std::endl;
            for(int column=0;column<13;column++){
                std::cin >> cas;
                _mapDat[line*2][column*2] = _mapDat[line*2][column*2+1] = cas;
                _mapDat[line*2+1][column*2] = _mapDat[line*2+1][column*2+1] = cas;
            }
        }
    }

    void mostrar(){
        std::cout << "NIVEL: " << _level << std::endl <<  std::endl;

        for(int line=0;line<26;line++){
            for(int column=0;column<26;column++){
                std::cout << _mapDat[line][column] << ", ";
            }
            std::cout << std::endl;
        }
    }

    bool leerDisco(int pos){
        FILE *p;
        bool res;
        p = fopen("mapas.dat", "rb");
        if(p == NULL) return false;
        fseek(p, pos * sizeof *this, 0);
        res = fread(this, sizeof *this, 1, p);
        fclose(p);
        return res;
    }

    void mostrarMapa(sf::RenderWindow & window);

    void setLevel(int lvl, TileMap &mapa);
    void setMapSprite(sf::Sprite *sprite, int x, int y){_mapa[x][y]=sprite;}

    bool collision(sf::Sprite sprite);
};

TileMap::TileMap(){
    _texture = new sf::Texture();
    _texture->loadFromFile("resources/400.png");

    int escala=16;

    for(int x=0;x<26;x++){
        for(int j=0;j<26;j++){
            int actual = LVL_1[x * 26 + j];

            switch(actual){
                case 1:
                    _sprite = new sf::Sprite(*_texture,sf::IntRect(4,4,16,16));

                    _sprite->setPosition(128+j*escala,32+x*escala);

                    _mapa[x][j] = _sprite;
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
                    _sprite = new sf::Sprite(*_texture,sf::IntRect(207,14,16,16));

                    _sprite->setPosition(128+j*escala,32+x*escala);

                    _mapa[x][j] = _sprite;
                    break;
                default:
                    _sprite = new sf::Sprite(*_texture,sf::IntRect(0,0,0,0));

                    _sprite->setPosition(j*escala,x*escala);

                    _mapa[x][j] = _sprite;
                    break;
            }
        }
    }
}

TileMap::~TileMap(){

    delete _texture;
    delete _sprite;
}

void TileMap::mostrarMapa(sf::RenderWindow & window){

    for(int x=0;x<26;x++){
        for(int j=0;j<26;j++){
                    window.draw(*_mapa[x][j]);
        }
    }
}

bool TileMap::collision(sf::Sprite sprite){

    for(int x=0;x<26;x++){
        for(int j=0;j<26;j++){
                if(_sprite->getGlobalBounds().intersects(_mapa[x][j]->getGlobalBounds())){
                    return true;
                }
        }
    }
    return false;
}

#endif // TILEMAP_H_INCLUDED
