#include "ShowingOptions.h"
#include<SFML/Graphics.hpp>
using namespace sf;
ShowingOptions::ShowingOptions(int width,int height)
{
	font.loadFromFile("Roboto-BoldCondensed.ttf");
	messages[0].setString("Continue");
	messages[0].setFillColor(Color(255, 215, 0));
	messages[0].setFont(font);
	messages[0].setPosition(Vector2f(150, 250));
	messages[0].setCharacterSize(70);

	messages[1].setString("Restart");
	messages[1].setFillColor(Color(135, 206, 235));
	messages[1].setFont(font);
	messages[1].setPosition(Vector2f(150, 450));
	messages[1].setCharacterSize(70);

	messages[2].setString("Back to mainmenu");
	messages[2].setFillColor(Color(135, 206, 235));
	messages[2].setFont(font);
	messages[2].setPosition(Vector2f(150, 650));
	messages[2].setCharacterSize(70);
	pressed = 0;
}

void ShowingOptions::moveup()
{
	if (pressed - 1 >= -1)
	{
		messages[pressed].setFillColor(Color(135, 206, 235));
		pressed--;
	}
	if (pressed == -1)
	{
		pressed = 2;
	}
	messages[pressed].setFillColor(Color(255, 215, 0));
}

void ShowingOptions::movedown()
{
	if (pressed + 1 <= 3)
	{
		messages[pressed].setFillColor(Color(135, 206, 235));
		pressed++;
	}
	if (pressed == 3)
	{
		pressed = 0;
	}
	messages[pressed].setFillColor(Color(255, 215, 0));
}

void ShowingOptions::move()
{
	for (int i = 0; i < 3; i++)
	{
		messages[i].move(4, 0);
	}
}

void ShowingOptions::draw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
		window.draw(messages[i]);
}

ShowingOptions::~ShowingOptions()
{
}
