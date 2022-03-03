#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <string>
#include <sstream>
#include "archivos.h"


class Menu{
private:
    sf::Font _font;
    sf::Text _text[60];
    int _maxNumItems;
    int _selectedItem=0;
    float _width;
    float _heigth;
    Menu *_submenu;
public:
    Menu(float width, float heigth, const char * aux, int num);
    Menu(float width, float heigth, int tipo);
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    void setSelectedItem(int num){_selectedItem=num;}
    int getPressedItem(){return _selectedItem;}
    void mainMenu();
    void levelMenu();
    void scoreMenu();
    void namesMenu(const char aux[20], int num);
    void ganador(Tank &ganador);
    void interfazScore(int p1, int p2);
};

Menu::Menu(float width, float heigth, int type){
    _width = width;
    _heigth = heigth;
    switch(type){
        case 1:
            mainMenu();
            break;
        case 2:
            levelMenu();
            break;
        case 3:
            scoreMenu();
            break;
        default:
            return;
            break;
    }
}

Menu::Menu(float width, float heigth, const char * aux, int num){
    _width = width;
    _heigth = heigth;

    namesMenu(aux,num);
}

void Menu::interfazScore(int p1, int p2){
    char aux[30];
    char aux2[30];

    char * score_1 = itoa(p1,aux,10);
    char * score_2 = itoa(p2,aux2,10);

    _maxNumItems=2;

    _font.loadFromFile("resources/game_over.ttf");
    _text[0].setFont(_font);
    _text[0].setColor(sf::Color::White);
    _text[0].setString(score_1);
    _text[0].setFont(_font);
    _text[0].setPosition(10,40);
    _text[0].setCharacterSize(50);

    _text[1].setFont(_font);
    _text[1].setColor(sf::Color::White);
    _text[1].setString(score_2);
    _text[1].setFont(_font);
    _text[1].setPosition(575,40);
    _text[1].setCharacterSize(50);
}

void Menu::namesMenu(const char aux[20], int num){
    _maxNumItems=2;

    _font.loadFromFile("resources/game_over.ttf");
    _text[0].setFont(_font);
    _text[0].setColor(sf::Color::Red);
    if(num==1){_text[0].setString("Nombre Jugador 1");}
    if(num==2){_text[0].setString("Nombre Jugador 2");}
    _text[0].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
    _text[0].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[1].setFont(_font);
    _text[1].setColor(sf::Color::White);
    _text[1].setString(aux);
    _text[1].setPosition(sf::Vector2f((_width/2-_text[1].getString().getSize()*_text[1].getCharacterSize()/2), 40 + _heigth/(_maxNumItems+1)));
    _text[1].setCharacterSize(50);
}

void Menu::ganador(Tank &ganador){

    char aux[30];

    _maxNumItems=3;

    _font.loadFromFile("resources/game_over.ttf");
    _text[0].setFont(_font);
    _text[0].setColor(sf::Color::White);
    _text[0].setString("Ganador");
    _text[0].setFont(_font);
    _text[0].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
    _text[0].setCharacterSize(50);

    char * AuxString = strcat(strcat(ganador.getNickPlayer(), " : "),itoa(ganador.getPoints(),aux,10));

    _font.loadFromFile("resources/game_over.ttf");
    _text[1].setFont(_font);
    _text[1].setColor(sf::Color::White);
    _text[1].setString(AuxString);
    _text[1].setFont(_font);
    _text[1].setPosition(sf::Vector2f((_width-(_text[1].getString().getSize()*_text[1].getCharacterSize())/2)/2, 40 + _heigth/(_maxNumItems+1)));
    _text[1].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[2].setFont(_font);
    _text[2].setColor(sf::Color::Red);
    _text[2].setString("- Press Enter -");
    _text[2].setFont(_font);
    _text[2].setPosition(sf::Vector2f((_width-(_text[2].getString().getSize()*_text[2].getCharacterSize())/2)/2, 80 + _heigth/(_maxNumItems+1)));
    _text[2].setCharacterSize(50);

}

void Menu::scoreMenu(){

    _maxNumItems=6;

    Scores scores;
    int pos = 0;

    char aux[30];

    while(scores.leerDisco(pos++)){

        _font.loadFromFile("resources/game_over.ttf");
        _text[0].setFont(_font);
        _text[0].setColor(sf::Color::Red);
        _text[0].setString("Records");
        _text[0].setFont(_font);
        _text[0].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
        _text[0].setCharacterSize(50);

        char * AuxString;

        if(scores.contarScores() >= 1){

            AuxString = strcat(strcat(scores.getName__(0), " : "),itoa(scores.getScore(0),aux,10));

        _text[1].setFont(_font);
        _text[1].setColor(sf::Color::White);
        _text[1].setString(AuxString);
        _text[1].setFont(_font);
        _text[1].setPosition(sf::Vector2f((_width-(_text[1].getString().getSize()*_text[1].getCharacterSize())/2)/2, 40 + _heigth/(_maxNumItems+1)));
        _text[1].setCharacterSize(50);
        }

        if(scores.contarScores()>=2){


            AuxString = strcat(strcat(scores.getName__(1), " : "),itoa(scores.getScore(1),aux,10));

        _text[2].setFont(_font);
        _text[2].setColor(sf::Color::White);
        _text[2].setString(AuxString);
        _text[2].setFont(_font);
        _text[2].setPosition(sf::Vector2f((_width-(_text[2].getString().getSize()*_text[2].getCharacterSize())/2)/2, 80 + _heigth/(_maxNumItems+1)));
        _text[2].setCharacterSize(50);

        }


        if(scores.contarScores()>=3){

            AuxString = strcat(strcat(scores.getName__(2), " : "),itoa(scores.getScore(2),aux,10));

        _text[3].setFont(_font);
        _text[3].setColor(sf::Color::White);
        _text[3].setString(AuxString);
        _text[3].setFont(_font);
        _text[3].setPosition(sf::Vector2f((_width-(_text[3].getString().getSize()*_text[3].getCharacterSize())/2)/2, 120 + _heigth/(_maxNumItems+1)));
        _text[3].setCharacterSize(50);

        }

        if(scores.contarScores()>=4){

           AuxString = strcat(strcat(scores.getName__(3), " : "),itoa(scores.getScore(3),aux,10));

        _text[4].setFont(_font);
        _text[4].setColor(sf::Color::White);
        _text[4].setString(AuxString);
        _text[4].setFont(_font);
        _text[4].setPosition(sf::Vector2f((_width-(_text[4].getString().getSize()*_text[4].getCharacterSize())/2)/2, 160 + _heigth/(_maxNumItems+1)));
        _text[4].setCharacterSize(50);
        }
    }

}

void Menu::levelMenu(){
    _maxNumItems=5;

    _font.loadFromFile("resources/game_over.ttf");
    _text[0].setFont(_font);
    _text[0].setColor(sf::Color::Red);
    _text[0].setString("Level 1");
    _text[0].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
    _text[0].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[1].setFont(_font);
    _text[1].setColor(sf::Color::White);
    _text[1].setString("Level 2");
    _text[1].setPosition(sf::Vector2f((_width-(_text[1].getString().getSize()*_text[1].getCharacterSize())/2)/2, 40 + _heigth/(_maxNumItems+1)));
    _text[1].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[2].setFont(_font);
    _text[2].setColor(sf::Color::White);
    _text[2].setString("Level 3");
    _text[2].setPosition(sf::Vector2f((_width-(_text[2].getString().getSize()*_text[2].getCharacterSize())/2)/2, 80 + _heigth/(_maxNumItems+1)));
    _text[2].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[3].setFont(_font);
    _text[3].setColor(sf::Color::White);
    _text[3].setString("Level 4");
    _text[3].setPosition(sf::Vector2f((_width-(_text[3].getString().getSize()*_text[3].getCharacterSize())/2)/2, 120 + _heigth/(_maxNumItems+1)));
    _text[3].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[4].setFont(_font);
    _text[4].setColor(sf::Color::White);
    _text[4].setString(">- Back");
    _text[4].setPosition(sf::Vector2f((_width-(_text[4].getString().getSize()*_text[4].getCharacterSize())/2)/2, 160 + _heigth/(_maxNumItems+1)));
    _text[4].setCharacterSize(50);
}

void Menu::mainMenu(){

    _maxNumItems=4;

    _font.loadFromFile("resources/game_over.ttf");
    _text[0].setFont(_font);
    _text[0].setColor(sf::Color::Red);
    _text[0].setString("Start");
    _text[0].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
    _text[0].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[1].setFont(_font);
    _text[1].setColor(sf::Color::White);
    _text[1].setString("Select Level");
    _text[1].setPosition(sf::Vector2f((_width-((_text[1].getString().getSize()-3)*_text[1].getCharacterSize())/2)/2, 40 + _heigth/(_maxNumItems+1)));
    _text[1].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[2].setFont(_font);
    _text[2].setColor(sf::Color::White);
    _text[2].setString("Records");
    _text[2].setPosition(sf::Vector2f((_width-((_text[2].getString().getSize())*_text[2].getCharacterSize())/2)/2, 80 + _heigth/(_maxNumItems+1)));
    _text[2].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[3].setFont(_font);
    _text[3].setColor(sf::Color::White);
    _text[3].setString("Exit");
    _text[3].setPosition(sf::Vector2f((_width-((_text[3].getString().getSize())*_text[3].getCharacterSize())/2)/2, 120 + _heigth/(_maxNumItems+1)));
    _text[3].setCharacterSize(50);

    }

void Menu::draw(sf::RenderWindow &window){
    for(int i=0; i<_maxNumItems; i++){
        window.draw(_text[i]);
    }
}

void Menu::moveUp()
{

    if(_selectedItem - 1 >= 0){
        _text[_selectedItem].setColor(sf::Color::White);
        _selectedItem--;
        _text[_selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::moveDown(){
    if(_selectedItem + 1 < _maxNumItems){
        _text[_selectedItem].setColor(sf::Color::White);
        _selectedItem++;
        _text[_selectedItem].setColor(sf::Color::Red);
    }
}

#endif // MENU_H_INCLUDED
