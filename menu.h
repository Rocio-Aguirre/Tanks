#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu{
private:
    sf::Font _font;
    sf::Text _text[60];
    int _maxNumItems;
    int _selectedItem=0;
public:
    Menu(float width, float heigth);
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    int getPressedItem(){return _selectedItem;}
};

Menu::Menu(float width, float heigth){
    _maxNumItems=4;

    /// ANTERIOR SetPosition
    //_text[3].setPosition(sf::Vector2f(width/2, 120 +heigth/(_maxNumItems+1)));

    _font.loadFromFile("resources/game_over.ttf");
    _text[0].setFont(_font);
    _text[0].setColor(sf::Color::Red);
    _text[0].setString("Start");
    _text[0].setPosition(sf::Vector2f((width-(_text[0].getString().getSize()*_text[0].getCharacterSize())/2)/2, heigth/(_maxNumItems+1)));
    _text[0].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[1].setFont(_font);
    _text[1].setColor(sf::Color::White);
    _text[1].setString("Choose level");
    _text[1].setPosition(sf::Vector2f((width-((_text[1].getString().getSize()-3)*_text[1].getCharacterSize())/2)/2, 40 + heigth/(_maxNumItems+1)));
    _text[1].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[2].setFont(_font);
    _text[2].setColor(sf::Color::White);
    _text[2].setString("View last score");
    _text[2].setPosition(sf::Vector2f((width-((_text[2].getString().getSize()-4)*_text[2].getCharacterSize())/2)/2, 80 + heigth/(_maxNumItems+1)));
    _text[2].setCharacterSize(50);

    _font.loadFromFile("resources/game_over.ttf");
    _text[3].setFont(_font);
    _text[3].setColor(sf::Color::White);
    _text[3].setString("Exit");
    _text[3].setPosition(sf::Vector2f((width-((_text[3].getString().getSize())*_text[3].getCharacterSize())/2)/2, 120 + heigth/(_maxNumItems+1)));
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
            std::cout << _selectedItem;
        _text[_selectedItem].setColor(sf::Color::White);
        std::cout << _selectedItem;
        _selectedItem++;
        _text[_selectedItem].setColor(sf::Color::Red);
    }
}

#endif // MENU_H_INCLUDED
