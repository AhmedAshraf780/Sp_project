#include "Menu.h"
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

Menu::Menu(int width, int height)
{
	font.loadFromFile("Roboto-BoldCondensed.ttf");
	// Play
	mainmenu[0].setFont(font);
	mainmenu[0].setString("Play");
	mainmenu[0].setFillColor(Color(255, 215, 0));
	mainmenu[0].setCharacterSize(100);
	mainmenu[0].setPosition(Vector2f(width / 4, height / (8)));
	
	//Achievement
	mainmenu[1].setFont(font);
	mainmenu[1].setString("Achievement");
	mainmenu[1].setFillColor(Color(135, 206, 235));
	mainmenu[1].setCharacterSize(100);
	mainmenu[1].setPosition(Vector2f(width / 7, height / (8) + 150));
	// About
	mainmenu[2].setFont(font);
	mainmenu[2].setString("About");
	mainmenu[2].setFillColor(Color(135, 206, 235));
	mainmenu[2].setCharacterSize(100);
	mainmenu[2].setPosition(Vector2f(width / 4, height / (8) + 300));
	//Exit
	mainmenu[3].setFont(font);
	mainmenu[3].setString("Exit");
	mainmenu[3].setFillColor(Color(135, 206, 235));
	mainmenu[3].setCharacterSize(100);
	mainmenu[3].setPosition(Vector2f(width / 4, height / (8) + 450));

	selected = 0;
}
void Menu::draw(RenderWindow & window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(mainmenu[i]);
	}
}
void Menu::moveup()
{
	if (selected - 1 >= -1)
	{
		mainmenu[selected].setFillColor(Color(135, 206, 235));
		selected--;
	}
	if (selected == -1)
	{
		selected = 3;
	}
		mainmenu[selected].setFillColor(Color(255, 215, 0));
}
void Menu::moveDown()
{
	if (selected + 1 <= 4)
	{
		mainmenu[selected].setFillColor(Color(135, 206, 235));
		selected++;
	}
	if (selected == 4)
	{
		selected = 0;
	}
		mainmenu[selected].setFillColor(Color(255, 215, 0));
}
void Menu::SetSelected(int n)
{
	selected = n;
}
Menu::~Menu()
{
}
