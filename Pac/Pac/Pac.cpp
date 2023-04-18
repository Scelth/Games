#include <SFML/Graphics.hpp>
#include <time.h>
#include "Global.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(W * ts, H * ts), "Pacman");

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

			if (q < 171 && life)
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

		if (q < 171 && life)
		{
			p.update();
			en.update();
		}

		window.clear(Color::Black);

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'A')
				{
					plat.setTextureRect(IntRect(0, 0, ts, ts));
				}

				if (TileMap[i][j] == 'C')
				{
					plat.setTextureRect(IntRect(ts * int(p.frame), ts * p.rotate, ts, ts));
				}

				if (TileMap[i][j] == ' ')
				{
					plat.setTextureRect(IntRect(ts, 0, ts, ts));
				}

				if (TileMap[i][j] == '1')
				{
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[0], ts, ts));
				}

				if (TileMap[i][j] == '2')
				{
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[1], ts, ts));
				}

				if (TileMap[i][j] == '3')
				{
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[2], ts, ts));
				}

				if (TileMap[i][j] == '4')
				{
					plat.setTextureRect(IntRect(ts * 5, ts * en.rotate[3], ts, ts));
				}

				if (TileMap[i][j] == 'B')
				{
					continue;
				}

				plat.setPosition(j * ts, i * ts);
				window.draw(plat);
			}
		}

		if (q == 171)
		{
			window.draw(youwin);
		}

		if (!life)
		{
			window.draw(youlose);
		}

		window.display();
	}

	return 0;
}