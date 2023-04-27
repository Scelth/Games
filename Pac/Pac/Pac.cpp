#include <SFML/Graphics.hpp>
#include <time.h>
#include "Global.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(W * Split, H * Split), "Pacman");

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

			if (q < 189 && Life)
			{
				if (event.type == Event::KeyPressed)
				{
					p.newx = p.x;
					p.newy = p.y;

					if (event.key.code == Keyboard::Right)
					{
						p.rotate = 1;
					}

					if (event.key.code == Keyboard::Left)
					{
						p.rotate = 2;
					}

					if (event.key.code == Keyboard::Up)
					{
						p.rotate = 3;
					}

					if (event.key.code == Keyboard::Down)
					{
						p.rotate = 4;
					}
				}
			}
		}

		if (q < 189 && Life)
		{
			p.update();
			en.update();
		}

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
					plat.setTextureRect(IntRect(Split * int(p.frame), Split * p.rotate, Split, Split));
				}

				if (Map[i][j] == ' ')
				{
					plat.setTextureRect(IntRect(Split, 0, Split, Split));
				}

				if (Map[i][j] == '1')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.rotate[0], Split, Split));
				}

				if (Map[i][j] == '2')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.rotate[1], Split, Split));
				}

				if (Map[i][j] == '3')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.rotate[2], Split, Split));
				}

				if (Map[i][j] == '4')
				{
					plat.setTextureRect(IntRect(Split * 5, Split * en.rotate[3], Split, Split));
				}

				if (Map[i][j] == 'B')
				{
					continue;
				}

				plat.setPosition(j * Split, i * Split);
				window.draw(plat);
			}
		}

		if (q == 189)
		{
			window.draw(youwin);
		}

		if (!Life)
		{
			window.draw(youlose);
		}

		window.display();
	}

	return 0;
}