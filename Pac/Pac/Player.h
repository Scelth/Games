#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Global.h"
#include "Map.h"

class Player
{
public:
	float frame = 0;
	int x = 9, y = 15;
	int newx = 0, newy = 0;
	int rotate = 1, ti = 0;

	void update()
	{
		frame += 0.01;
		if (frame > 5)
			frame -= 5;

		ti++;
		if (ti >= 300)
		{
			switch (rotate)
			{
			case 1:
				if (TileMap[y][newx + 1] != 'A')
					newx += 1;
				break;

			case 2:
				if (TileMap[y][newx - 1] != 'A')
					newx -= 1;
				break;

			case 3:
				if (TileMap[newy - 1][x] != 'A')
					newy -= 1;
				break;

			case 4:
				if (TileMap[newy + 1][x] != 'A')
					newy += 1;
				break;
			}

			ti = 0;
		}

		if (TileMap[newy][newx] == ' ' || TileMap[newy][newx] == 'B')
		{
			if (TileMap[newy][newx] == ' ')
				q++;

			if (TileMap[newy][newx] == '1' || TileMap[newy][newx] == '2' || TileMap[newy][newx] == '3' || TileMap[newy][newx] == '4')
				life = false;

			TileMap[y][x] = 'B';

			TileMap[newy][newx] = 'C';

			x = newx;
			y = newy;
		}

		if (newy == 9 && (newx == 0 || newx == 18))
		{
			if (newx == 0)
				newx = 17;

			else
				newx = 1;

			TileMap[y][x] = 'B';
			TileMap[newy][newx] = 'C';

			x = newx;
			y = newy;
		}
	}
};