#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include"Menu.h"
#include"levels.h"
#include"GameOver.h"
#include"ShowingOptions.h"
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<ostream>
#include<istream>
#include<sstream>
using namespace std;
using namespace sf;
int i = 0;
struct Bird
{
	
	string name;
	int score=0;
	// Bird setup

	float birdVelocity = 0.0f;
	float gravity = 0.5f;
	Texture player;
	RectangleShape bird;
	void Atrributes()
	{
		player.loadFromFile("bird1.png");
		bird.setTexture(&player);
		bird.setPosition(Vector2f(300, 400));
		bird.setSize(Vector2f(125, 100));
		bird.setScale(0.5, 0.3);
		bird.setTextureRect(IntRect(0, 0, 255, 180));
	}
	void animation()
	{
		i++;
		i %= 3;
		bird.setTextureRect(IntRect((i*255), 0, 255, 180));
	}
	
}Flappy;
struct Pipe
{
	Texture Pipetp, Pipebm,flag;
	Sprite PipeOftop[25], PipeOfbottom[25];
	RectangleShape Flag;
	void attributes()
	{
		for (int i = 0; i < 25; i++)
		{
			Pipetp.loadFromFile("pipe.png");
			PipeOftop[i].setTexture(Pipetp);
			
			Pipebm.loadFromFile("coloumn.png");
			PipeOfbottom[i].setTexture(Pipebm);
			
		}
		flag.loadFromFile("flag2mod-removebg-preview2.png");
		Flag.setTexture(&flag);
	}
	void setPositions()
	{
		
		for (int i = 0; i < 10; i++)
		{
			PipeOfbottom[i].setPosition(Vector2f(1200 + (i * 350), 510));
			PipeOfbottom[i].setScale(3, 2.5);
		}
		 
		for (int i = 10; i < 20; i++)
		{
			PipeOfbottom[i].setPosition(Vector2f(5000 + (i * 75), 510));
			PipeOfbottom[i].setScale(3,2.5);
		}
		
		for (int i = 20; i < 25; i += 2)
		{
			PipeOfbottom[i].setPosition(Vector2f(2500 + (i * 250), 500));
			PipeOfbottom[i].setScale(3, 2.6);
		}
		for (int i = 21; i < 25; i += 2)
		{
			PipeOfbottom[i].setPosition(Vector2f(2500 + (i * 250), 555));
			PipeOfbottom[i].setScale(3, 2.2);
		}
		
		for (int i = 0; i < 10; i++)
		{
			PipeOftop[i].setPosition(Vector2f(1200 + (i * 350), 1));
			PipeOftop[i].setScale(3.0, 2.6);
		}
		 
		for (int i = 10; i < 20; i++)
		{
			PipeOftop[i].setPosition(Vector2f(5000 + (i * 75), 2));
			PipeOftop[i].setScale(3, 2.6);
		}
		
		for (int i = 20; i < 25; i += 2)
		{
			PipeOftop[i].setPosition(Vector2f(2500 + (i * 250), 2));
			PipeOftop[i].setScale(3, 2.4);
		}
		for (int i = 21; i < 25; i += 2)
		{
			PipeOftop[i].setPosition(Vector2f(2500 + (i * 250), 2));
			PipeOftop[i].setScale(3, 3);
		}
		Flag.setPosition(Vector2f(9300, -3));
		Flag.setSize(Vector2f(200, 880));
	}
	void draw(RenderWindow& window)
	{
		for (int i = 0; i < 25; i++)
		{
			window.draw(PipeOfbottom[i]);
			window.draw(PipeOftop[i]);
		}
		window.draw(Flag);
	}
	void move(int a,int b=0)
	{
		for (int i = 0; i < 25; i++)
		{
			PipeOfbottom[i].move(-a, 0);
			PipeOftop[i].move(-a, 0);

		}
		Flag.move(-a, 0);
	}
	


}levelonepipes;
int pagenum = 1000;
string name;
void pname(RenderWindow& window, string & name);
void selectedLevels(RenderWindow& window);
void freepalstine(RenderWindow & window);
void showingoptions(RenderWindow& window);
void leaderboard(RenderWindow& window);
void Gameover(RenderWindow& window);
void winning(RenderWindow& window);
int main()
{
	int count = 0;

	RenderWindow window(VideoMode(900, 1000), "Flappy Bird");

	Menu menu(700, 900);
	levels stages(700, 900);
	Texture BackgroundMenu;
	BackgroundMenu.loadFromFile("copy 2.jpg");
	Sprite Background;
	Background.setTexture(BackgroundMenu);
	window.setFramerateLimit(60);
	//Map
	Texture map;
	map.loadFromFile("wp6956942.png");
	Sprite Map[2];
	for (int i = 0; i < 2; i++)
	{
		Map[i].setTexture(map);
		Map[i].setPosition(Vector2f(i * 1920, 0));
	}
	//ground
	Texture gr;
	gr.loadFromFile("ground2.png");
	Sprite Gr[2];
	for (int i = 0; i < 2; i++)
	{
		Gr[i].setTexture(gr);
		Gr[i].setPosition(Vector2f(i * 1920, 850));
	}


	Clock clock;
	//Font 
	Font font;
	font.loadFromFile("Roboto-BoldCondensed.ttf");

	//sounds
	SoundBuffer wing,death,points,countdown,menusound,clap;
	wing.loadFromFile("sfx_wing.wav");
	Sound Wing(wing);
	Wing.setVolume(20);
	death.loadFromFile("sfx_die.wav");
	Sound Death(death);
	points.loadFromFile("sfx_point.wav");
	Sound Points(points);
	countdown.loadFromFile("countdown.mp3");
	Sound Count(countdown);
	menusound.loadFromFile("soundmenu.mp3");
	Sound menus(menusound);
	menus.setVolume(80);
	clap.loadFromFile("clapping.mp3");
	Sound Clap(clap);
	//elzarzeer
	Texture za;
	za.loadFromFile("elzarzeer.jpg");
	Sprite zarzeer(za);
	
	levelonepipes.attributes();
	levelonepipes.setPositions();
	menus.play();
	
	

	while (true)
	{
		if (pagenum == 1000)
		{
			while (true)
			{
				window.clear();
				window.draw(zarzeer);
				window.display();
				if (clock.getElapsedTime().asSeconds() > 3)
				{
					clock.restart();
					pagenum = 0;
					break;
				}
			}
		}
		if (pagenum == 0)
		{
			menus.Playing;
			
			
		while (window.isOpen())
		{
			
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					break;
				}
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Up)
					{
						menu.moveup();
					}
					if (event.key.code == Keyboard::Down)
					{
						menu.moveDown();
					}
				}
				if (event.key.code == Keyboard::Return)
				{
					if (menu.pressed() == 0)
					{
						pagenum = 1;
					}
					if (menu.pressed() == 1)
					{
						pagenum = 6;
					}
					if (menu.pressed() == 2)
					{
						pagenum = 7;
					}
					if (menu.pressed() == 3)
					{
						pagenum = -1;
					}
					
				}
			}
			window.clear();
			

			if (pagenum != 0) break;
			window.draw(Background);
		    menu.draw(window);
			freepalstine(window);
			
			window.display();
		}
		
		}
		if (pagenum == -1)
		{
			window.close();
			break;
		}
		if (pagenum == 1)
		{
			pname(window,name);
		}
		if (pagenum == 2)
		{
			
				selectedLevels(window);
		}
		if (pagenum == 3)
		{
			Flappy.Atrributes();
			Clock c;
			bool exit = true;
			Texture ayhaga;
			ayhaga.loadFromFile("copy 2.jpg");
			Sprite Ayhaga(ayhaga);
			Text ready[5];
			ready[0].setString("3");
			ready[1].setString("2");
			ready[2].setString("1");
			ready[4].setString("Are you readyyyy?? ");
			ready[4].setPosition(Vector2f(200, 30));
			ready[4].setCharacterSize(70);
			ready[4].setFillColor(Color(255, 215, 0));
			ready[4].setFont(font);
			ready[3].setString("0");

			
			
			for (int i = 0; i < 4; i++)
			{
				ready[i].setFont(font);
				ready[i].setCharacterSize(150);
				ready[i].setFillColor(Color(255, 215, 0));
				ready[i].setPosition(Vector2f(400, 350));
				
			}
			
			// level one will be here
			while (exit)
			{
				menus.stop();
				Count.play();
				while (true)
				{
					window.clear();
					window.draw(Ayhaga);
					window.draw(ready[4]);
					window.draw(ready[0]);
					window.display();
					if (c.getElapsedTime().asSeconds() > 1)
						break;
				}while (true)
				{
					window.clear();
					window.draw(Ayhaga);
					window.draw(ready[4]);
					window.draw(ready[1]);
					window.display();
					if (c.getElapsedTime().asSeconds() > 2)
						break;
				}while (true)
				{
					window.clear();
					window.draw(Ayhaga);
					window.draw(ready[4]);
					window.draw(ready[2]);
					window.display();
					if (c.getElapsedTime().asSeconds() > 3)
						break;
				}while (true)
				{
					window.clear();
					window.draw(Ayhaga);
					window.draw(ready[4]);
					window.draw(ready[3]);
					window.display();
					if (c.getElapsedTime().asSeconds() > 5)
						break;
				}
				exit = false;
				

			}
			while (window.isOpen())
			{
				
				
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && Flappy.bird.getPosition().y >= 40)
					{
						Wing.play();
						Flappy.birdVelocity = -6.0f; // Jump
						Flappy.animation();
					}

					




				}
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					pagenum = 10;
					break;
				}
				// Update bird position
				Flappy.birdVelocity += Flappy.gravity;
				Flappy.bird.move(0, Flappy.birdVelocity);
				//collision
				for (int i = 0; i < 25; i++)
				{
					if (Flappy.bird.getGlobalBounds().intersects(levelonepipes.PipeOfbottom[i].getGlobalBounds()) || Flappy.bird.getGlobalBounds().intersects(levelonepipes.PipeOftop[i].getGlobalBounds())||Flappy.bird.getPosition().y>=840)
					{
						count++;
						
					}
				}
				
				
				
				if (count > 1)
				{
					Clock c2;
					while (c2.getElapsedTime().asSeconds()<2)
					{

						Flappy.bird.move(0, 0);
						for (int i = 0; i < 2; i++)
						{
							Gr[i].move(0, 0);
							Map[i].move(0, 0);
						}
						
					}
					c2.restart();
					count = 0;
					pagenum = 12;
					break;
				}
				else
				{
					for (int i = 0; i < 2; i++)
					{
						Gr[i].move(-2, 0);
						Map[i].move(-2, 0);
					}
					Flappy.bird.move(0, 0);
				}

				// the end of the game
				if (Flappy.bird.getGlobalBounds().intersects(levelonepipes.Flag.getGlobalBounds()))
				{
					Clock cl;
					Clap.play();
					while (cl.getElapsedTime().asSeconds() <5)
					{
						Flappy.bird.move(0, 0);
						for (int i = 0; i < 2; i++)
						{
							Gr[i].move(0, 0);
							Map[i].move(0, 0);
						}

					}
					cl.restart();
					Clap.stop();
					levelonepipes.setPositions();
					Flappy.bird.setPosition(Vector2f(300, 400));
					winning(window);
					
					break;
					
				}

				
				
				
				
				
				
				

				for (int i = 0; i < 2; i++)
				{
					
					Map[i].move(-2, 0);
					if (Map[i].getPosition().x <= -1920)
					{
						Map[i].setPosition(Vector2f(1920, 0));
					}
					else if (Map[i].getPosition().x <= -1920 )
					{
						Map[i].setPosition(Vector2f(1920, 0));	
					}
				}
				for (int i = 0; i < 2; i++)
				{
					Gr[i].move(-2, 0);
					if (Gr[i].getPosition().x <= -1920)
					{
						Gr[i].setPosition(Vector2f(1920, 850));
					}
					else if (Gr[i].getPosition().x <= -1920)
					{
						Gr[i].setPosition(Vector2f(1920, 850));
					}
				}
				
				levelonepipes.move(4, 0);
				
			
				
				
				window.clear();
				for (int i = 0; i < 2; i++)
					window.draw(Map[i]);
				for (int i = 0; i < 2; i++)
					window.draw(Gr[i]);
				levelonepipes.draw(window);
				window.draw(Flappy.bird);
				window.display();
			}
		}
		//if (pagenum == 4)
		//{
		//	//level 2 will be here
		//}
		//if (pagenum == 5)
		//{
		//	//level 3 will be here
		//}
		if (pagenum == 6)
		{
			//Achievements will be here
			leaderboard(window);
		 
		}
		//if (pagenum == 7)
		//{
		//	//About will be here
		//}
		if (pagenum == 10)
		{
			menus.play();
			showingoptions(window);
		}
		if (pagenum == 12)
		{
			Gameover(window);
		}
		

	}
	
}
void pname(RenderWindow & window, string&name)
{
	
	Texture backg;
	backg.loadFromFile("copy 2.jpg");
	Sprite back;
	back.setTexture(backg);
	if (!name.empty())name.clear();
	Font font;
	font.loadFromFile("Roboto-BoldCondensed.ttf");
	Text textone, texttwo;
	textone.setFont(font);
	texttwo.setFont(font);
	textone.setString("Enter your Name");
	textone.setPosition(10, 25);
	texttwo.setPosition(10, 150);
	textone.setCharacterSize(70);
	texttwo.setCharacterSize(70);
	textone.setFillColor(Color(135, 206, 235));
	texttwo.setFillColor(Color(255, 215, 0));
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::TextEntered)
			{
				name += static_cast<char>(event.text.unicode);
				
				
			}
			
			if (Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() > 0)
			{
					name.pop_back();
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)&&name.size()>4)
			{
				Flappy.name = name;
				ofstream offile;
				offile.open("history.txt", ios::app);
				offile << "Name" << "\t\t" << "Score"<<"*"<< endl;
				offile << Flappy.name << "  " << "*" << endl;
				pagenum = 2;
				return;
					
			}
				if (event.key.code == Keyboard::Escape)
				{
					pagenum = 0;
					return;
				}
			
		}
		
		texttwo.setString(name);
		window.clear();
		window.draw(back);
		window.draw(textone);
		window.draw(texttwo);
		window.display();
	}
}
void selectedLevels(RenderWindow& window)
{
	levels stages(1440, 900);
	Texture BackgroundMenu;
	BackgroundMenu.loadFromFile("copy 2.jpg");
	Sprite Background;
	Background.setTexture(BackgroundMenu);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				break;
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)

					stages.moveUp();

				if (event.key.code == Keyboard::Down)

					stages.moveDown();

			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				if (stages.getselected() == 0)
				{
					pagenum = 3;
					return;
				}
				if (stages.getselected() == 1)
				{
					pagenum = 4;
					return;
				}
				if (stages.getselected() == 2)
				{
					pagenum = 5;
					return;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				pagenum = 0;
				return;
			}
		}
		window.clear();
		window.draw(Background);
		stages.draw(window);
		window.display();
	}
}
void freepalstine(RenderWindow& window)
{
	Font font2;
	font2.loadFromFile("Roboto-BoldCondensed.ttf");
	Text t1, t2, t3;
	t1.setString("#free");
	t1.setCharacterSize(50);
	t1.setFillColor(Color::Green);
	t1.setFont(font2);
	t1.setPosition(Vector2f(550, 10));

	t2.setString("pals");
	t2.setCharacterSize(50);
	t2.setFillColor(Color::White);
	t2.setFont(font2);
	t2.setPosition(Vector2f(660, 10));

	t3.setString("tine");
	t3.setCharacterSize(50);
	t3.setFillColor(Color::Red);
	t3.setFont(font2);
	t3.setPosition(Vector2f(740, 10));
	window.draw(t1);
	window.draw(t2);
	window.draw(t3);
}
void showingoptions(RenderWindow& window)
{

	
	ShowingOptions sh(700,900);
	 Texture pi;
	pi.loadFromFile("copy 2.jpg");
	Sprite p2;
	p2.setTexture(pi);
	while (window.isOpen())
	{
		window.clear();
		window.draw(p2);
		sh.draw(window);
		window.display();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)

					sh.moveup();

				if (event.key.code == Keyboard::Down)

					sh.movedown();

			}
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				if (sh.returnpressed() == 0)
				{
					pagenum = 3;
					return;
				}
				if (sh.returnpressed() == 1)
				{
					levelonepipes.setPositions();
					pagenum = 3;
					return;
					
				}
				 if (sh.returnpressed() == 2)
				 {
					 levelonepipes.setPositions();
					 pagenum = 0;
					 return;
				 }
			}
		}
		
	}
	
}
void leaderboard(RenderWindow& window)
{
	Texture t2;
	t2.loadFromFile("copy 2.jpg");
	Sprite sp(t2);
	sp.setPosition(0, 0);
	Font font;
	font.loadFromFile("Roboto-BoldCondensed.ttf");
	Text tex[100];
	for (int i = 0; i < 60; i++) {
		tex[i].setFont(font);
		tex[i].setCharacterSize(50);
		tex[i].setFillColor(Color(255, 215, 0));
	}

	ifstream infile;
	infile.open("history.txt", ios::in);

	vector<string> lines;
	string line;
	while (getline(infile, line, '*'))
	{
		lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i++)
	{
		tex[i].setString(lines[i]);
		tex[i].setPosition(Vector2f(100, 50 *i));
	}
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				pagenum = 0;
				return;
			}
		}
		window.clear();
		window.draw(sp);
		for (int i = 0; i < lines.size(); i++)
		{
			window.draw(tex[i]);
		}
		window.display();
	}

}
void Gameover( RenderWindow &window)
{
	GameOver game1(900,1000);
	Texture BackgroundMenu;
	BackgroundMenu.loadFromFile("copy 2.jpg");
	Sprite Background;
	Background.setTexture(BackgroundMenu);
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)

					game1.moveup_gameover();

				if (event.key.code == Keyboard::Down)

					game1.movedown_gameover();

			}
			if (event.type==Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{

				if (game1.Getselected() == 0)
				{
					levelonepipes.setPositions();
					pagenum = 3;
					return;
				}
				if (game1.Getselected() == 1)
				{
					levelonepipes.setPositions();
					pagenum = 4;
					return;

				}
				if (game1.Getselected() == 2)
				{
					levelonepipes.setPositions();
					pagenum = 0;
					return;
				}
				}
			}
		}
		window.clear();
		window.draw(Background);
		game1.Draw_gameover(window);
		window.display();
	}
}
void winning(RenderWindow &window)
{
	GameOver game1(900, 1000);
	Texture BackgroundMenu;
	BackgroundMenu.loadFromFile("copy 2.jpg");
	Sprite Background;
	Background.setTexture(BackgroundMenu);
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Up)

					game1.moveup_winning();

				if (event.key.code == Keyboard::Down)

					game1.movedown_winning();

			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Return)
				{

					if (game1.Getselected2() == 0)
					{
						levelonepipes.setPositions();
						pagenum = 3;
						return;
					}
					if (game1.Getselected2() == 1)
					{
						levelonepipes.setPositions();
						pagenum = 4;
						return;

					}
					if (game1.Getselected2() == 2)
					{
						levelonepipes.setPositions();
						pagenum = 0;
						return;
					}
				}
			}
		}
		window.clear();
		window.draw(Background);
		game1.winningdraw(window);
		window.display();
	}

}
