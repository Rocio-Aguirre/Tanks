#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

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
    //_text[1].setPosition(sf::Vector2f((_width-((_text[1].getString().getSize())*_text[1].getCharacterSize())/2)/2, 40 + _heigth/(_maxNumItems+1)));
    _text[1].setCharacterSize(50);
}

void Menu::scoreMenu(){

    _maxNumItems=6;

    Scores scores;
    int pos = 0;

    while(scores.leerDisco(pos++)){

//    std::string str = std::string(scores.getName(0));
//        char name[20];
//        strcpy(name, scores.getName(0));
//        std::string tmp_string(name);

        _font.loadFromFile("resources/game_over.ttf");
        _text[0].setFont(_font);
        _text[0].setColor(sf::Color::White);
        _text[0].setString("Records");
        _text[0].setFont(_font);
        _text[0].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
        _text[0].setCharacterSize(50);

    }



//    _font.loadFromFile("resources/game_over.ttf");
//    _text[1].setFont(_font);
//    _text[1].setColor(sf::Color::White);
//    _text[1].setString("Nombre 1");
//    _text[1].setPosition(sf::Vector2f((_width-((_text[1].getString().getSize()-3)*_text[1].getCharacterSize())/2)/2, 40 + _heigth/(_maxNumItems+1)));
//    _text[1].setCharacterSize(50);
//
//    _font.loadFromFile("resources/game_over.ttf");
//    _text[2].setFont(_font);
//    _text[2].setColor(sf::Color::White);
//    _text[2].setString(">- Back");
//     _text[5].setPosition(sf::Vector2f((_width-((_text[2].getString().getSize()-6)*_text[2].getCharacterSize())/2)/2, 80 + _heigth/(_maxNumItems+1)));
//    _text[2].setCharacterSize(50);
//
//    _font.loadFromFile("resources/game_over.ttf");
//    _text[3].setFont(_font);
//    _text[3].setColor(sf::Color::White);
//    _text[3].setString("Highest Scores");
//    _text[3].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
//    _text[3].setCharacterSize(50);
//
//    _font.loadFromFile("resources/game_over.ttf");
//    _text[3].setFont(_font);
//    _text[3].setColor(sf::Color::White);
//    _text[3].setString("Highest Scores");
//    _text[3].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
//    _text[3].setCharacterSize(50);
//
//    _font.loadFromFile("resources/game_over.ttf");
//    _text[4].setFont(_font);
//    _text[4].setColor(sf::Color::White);
//    _text[4].setString("Highest Scores");
//    _text[4].setPosition(sf::Vector2f((_width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, _heigth/(_maxNumItems+1)));
//    _text[4].setCharacterSize(50);
//
//    _font.loadFromFile("resources/game_over.ttf");
//    _text[5].setFont(_font);
//    _text[5].setColor(sf::Color::Red);
//    _text[5].setString("Puntaje ");
//     _text[5].setPosition(sf::Vector2f((_width-((_text[2].getString().getSize()-6)*_text[2].getCharacterSize())/2)/2, 80 + _heigth/(_maxNumItems+1)));
//    _text[5].setCharacterSize(50);

}

void Menu::levelMenu(){
    _maxNumItems=3;

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
    _text[1].setPosition(sf::Vector2f((_width-((_text[1].getString().getSize()-3)*_text[1].getCharacterSize())/2)/2, 40 + _heigth/(_maxNumItems+1)));
    _text[1].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[2].setFont(_font);
    _text[2].setColor(sf::Color::White);
    _text[2].setString(">- Back");
    _text[2].setPosition(sf::Vector2f((_width-((_text[2].getString().getSize()-6)*_text[2].getCharacterSize())/2)/2, 80 + _heigth/(_maxNumItems+1)));
    _text[2].setCharacterSize(50);

}

void Menu::mainMenu(){

    _maxNumItems=4;

    /// ANTERIOR SetPosition
    //_text[3].setPosition(sf::Vector2f(width/2, 120 +heigth/(_maxNumItems+1)));

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
//        std::cout << _selectedItem;
        _text[_selectedItem].setColor(sf::Color::White);
        _selectedItem--;
        std::cout << _selectedItem << std::endl;
        _text[_selectedItem].setColor(sf::Color::Red);
    }
}

void Menu::moveDown(){
    if(_selectedItem + 1 < _maxNumItems){
//            std::cout << _selectedItem;
        _text[_selectedItem].setColor(sf::Color::White);
        _selectedItem++;
        std::cout << _selectedItem << std::endl;
        _text[_selectedItem].setColor(sf::Color::Red);
    }
}

#endif // MENU_H_INCLUDED
