#include <SFML/Graphics.hpp>
#include <time.h>
#include "Global.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(W * Split, H * Split + 3 * Split), "Pac-man!");

	Image icon;
	icon.loadFromFile("Image/logo.png");
	const Uint8* pixels = icon.getPixelsPtr();
	window.setIcon(icon.getSize().x, icon.getSize().y, pixels);


	Texture t;
	t.loadFromFile("Image/title.png");
	Sprite plat(t);

	Texture yw;
	yw.loadFromFile("Image/youwin.png");
	Sprite youwin(yw);
	youwin.setPosition(100, 210);

	Texture yl;
	yl.loadFromFile("Image/youlose.png");
	Sprite youlose(yl);
	youlose.setPosition(100, 210);

	Texture sc;
	sc.loadFromFile("Image/score.png");
	Score score(sc);

	Player p;
	Enemy en;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			if (q < 194 && Life)
			{
				if (event.type == Event::KeyPressed)
				{
					p.NewX = p.x;
					p.NewY = p.y;

					if (event.key.code == Keyboard::Right)
					{
						p.Rotate = 1;
					}

					if (event.key.code == Keyboard::Left)
					{
						p.Rotate = 2;
					}

					if (event.key.code == Keyboard::Up)
					{
						p.Rotate = 3;
					}

					if (event.key.code == Keyboard::Down)
					{
						p.Rotate = 4;
					}
				}
			}
		}

		if ((q == 194 || !Life) && RestartTime != 0) 
		{
			RestartTime--;

			if (RestartTime == 0) 
			{
				for (int i = 0; i < H; i++)
				{
					for (int j = 0; j < W; j++)
					{
						if (Map[i][j] == 'B')
						{
							Map[i][j] = ' ';
						}
					}
				}

				p.Restart = true;
				en.Restart = true;

				q = 0;
				Life = true;
				RestartTime = 5000;
			}
		}

		score.c = q;

		if (!Life) 
		{
			for (int i = 0; i < H; i++)
			{
				for (int j = 0; j < W; j++)
				{
					if (Map[i][j] != 'A')
					{
						Map[i][j] = 'B';
					}
				}
			}
		}

		if (q < 194 && Life)
		{
			p.Update();
			en.Update();
		}

		score.Update();
		window.clear(Color::Black);

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (Map[i][j] == 'A')
				{
					plat.setTextureRect(IntRect(0, 0, Split, Split));
				}

				if (Map[i][j] == 'C')
				{
					plat.setTextureRect(IntRect(Split * int(p.frame), Split * p.Rotate, Split, Split));
				}

				if (Map[i][j] == ' ')
				{
					plat.setTextureRect(IntRect(Split, 0, Split, Split));
				}

				if (Map[i][j] == '1')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.Rotate[0], Split, Split));
				}

				if (Map[i][j] == '2')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.Rotate[1], Split, Split));
				}

				if (Map[i][j] == '3')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.Rotate[2], Split, Split));
				}

				if (Map[i][j] == '4')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.Rotate[3], Split, Split));
				}

				if (Map[i][j] == 'B')
				{
					continue;
				}

				plat.setPosition(j * Split, i * Split);
				window.draw(plat);
			}
		}

		if (q == 194)
		{
			window.draw(youwin);
		}

		if (!Life)
		{
			window.draw(youlose);
		}

		for (int i = 0; i < 3; i++)
		{
			if (score.vid[i])
			{
				window.draw(score.sec[i]);
			}
		}

		window.display();
	}

	return 0;
}