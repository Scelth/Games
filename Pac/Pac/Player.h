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
		{
			frame -= 5;
		}

		ti++;

		if (ti >= 300)
		{
			switch (rotate)
			{
			case 1:
				if (Map[y][newx + 1] != 'A')
				{
					newx += 1;
				}

				break;

			case 2:
				if (Map[y][newx - 1] != 'A')
				{
					newx -= 1;
				}

				break;

			case 3:
				if (Map[newy - 1][x] != 'A')
				{
					newy -= 1;
				}

				break;

			case 4:
				if (Map[newy + 1][x] != 'A')
				{
					newy += 1;
				}

				break;
			}

			ti = 0;
		}

		if (Map[newy][newx] == ' ' || Map[newy][newx] == 'B')
		{
			if (Map[newy][newx] == ' ')
			{
				q++;
			}

			if (Map[newy][newx] == '1' || Map[newy][newx] == '2' || Map[newy][newx] == '3' || Map[newy][newx] == '4')
			{
				Life = false;
			}

			Map[y][x] = 'B';

			Map[newy][newx] = 'C';

			x = newx;
			y = newy;
		}

		if (newy == 9 && (newx == 0 || newx == 18))
		{
			if (newx == 0)
			{
				newx = 17;
			}

			else
			{
				newx = 1;
			}

			Map[y][x] = 'B';
			Map[newy][newx] = 'C';

			x = newx;
			y = newy;
		}
	}
};