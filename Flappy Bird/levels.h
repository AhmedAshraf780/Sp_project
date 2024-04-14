#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

class levels
{
public:
	levels(int width, int height);
	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();
	void setselected(int n);
	int getselected()
	{
		return selected2;
	}
	Text levelmenu[3];
	~levels();
private:
	int selected2;
	Font font;
};

