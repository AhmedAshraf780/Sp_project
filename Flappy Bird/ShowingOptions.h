#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class ShowingOptions
{
public:
	ShowingOptions(int width,int height);
	void moveup();
	void movedown();
	void move();
	void draw(RenderWindow& window);
	int returnpressed()
	{
		return pressed;
	}
	~ShowingOptions();
private:
	int pressed;
	Text messages[3];
	Font font;
	

};

