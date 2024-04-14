#pragma once
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class GameOver
{
public:
	GameOver(int width,int height);
	void moveup_gameover();
	void movedown_gameover();
	void Draw_gameover(RenderWindow& window);
	int Getselected()
	{
		return selected;
	}
	int Getselected2()
	{
		return selected2;
	}
	void winningdraw(RenderWindow& window);
	void moveup_winning();
	void movedown_winning();
	~GameOver();
	Text gameover[3],winning[3];
	Text gameO;
	Font font;
	int selected;
	int selected2;
};

