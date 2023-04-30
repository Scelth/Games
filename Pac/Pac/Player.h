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
	int NewX = 0, NewY = 0;
	int Rotate = 1, Time = 0;
	bool Restart = false;

	void Update()
	{
		if (Restart) 
		{
			Map[y][x] = ' ';

			x = 9;
			y = 15;

			Map[y][x] = 'C';

			NewX = x;
			NewY = y;

			Restart = false;
		}

		else
		{
			frame += 0.01;
			if (frame > 5)
			{
				frame -= 5;
			}

			Time++;

			if (Time >= 300)
			{
				switch (Rotate)
				{
				case 1:
					if (Map[y][NewX + 1] != 'A')
					{
						NewX += 1;
					}

					break;

				case 2:
					if (Map[y][NewX - 1] != 'A')
					{
						NewX -= 1;
					}

					break;

				case 3:
					if (Map[NewY - 1][x] != 'A')
					{
						NewY -= 1;
					}

					break;

				case 4:
					if (Map[NewY + 1][x] != 'A')
					{
						NewY += 1;
					}

					break;
				}

				Time = 0;
			}
		}

		if ((Map[NewY][NewX] == ' ' || Map[NewY][NewX] == 'B')) 
		{
			if (Map[NewY][NewX] == ' ')
			{
				q++;
			}

			Map[y][x] = 'B';

			Map[NewY][NewX] = 'C';

			x = NewX;
			y = NewY;
		}

		if (NewY == 9 && (NewX == 0 || NewX == 18))
		{
			if (NewX == 0)
			{
				NewX = 17;
			}

			else
			{
				NewX = 1;
			}

			Map[y][x] = 'B';
			Map[NewY][NewX] = 'C';

			x = NewX;
			y = NewY;
		}
	}
};