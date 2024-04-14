#pragma once
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Menu
{
public:
    Text mainmenu[4];
    Menu(int wigth, int height);
    void draw(RenderWindow& window);
    void moveup();
    void moveDown();
    void SetSelected(int n);
    int pressed() {
        return selected;
    }
    ~Menu();
private:
    int selected;
    Font font;



};

