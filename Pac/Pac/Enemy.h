#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Global.h"
#include "Map.h"
#include "Player.h"

class Enemy
{
public:
	int x[4] = { 1, 17 , 1, 17 }, y[4] = { 1, 1, 19, 19 };
	int NewX[4] = { 0 , 0 , 0, 0 }, NewY[4] = { 0, 0, 0, 0 };
	int Rotate[4] = { 1, 1, 1, 1 }, Time = 0;
	bool Restart = false;

	void Update()
	{

		if (Restart)
		{
			for (int i = 0; i < 4; i++)
			{
				Map[y[i]][x[i]] = ' ';
			}

			x[0] = 1; x[1] = 17; x[2] = 1; x[3] = 17;
			y[0] = 1; y[1] = 1; y[2] = 19; y[3] = 19;

			Map[y[0]][x[0]] = '1';
			Map[y[1]][x[1]] = '2';
			Map[y[2]][x[2]] = '3';
			Map[y[3]][x[3]] = '4';

			for (int i = 0; i < 4; i++) {
				NewX[i] = x[i];
				NewY[i] = y[i];
			}

			Restart = false;
		}

		else
		{
			Time++;

			if (Time >= 300)
			{
				for (int i = 0; i < 4; i++)
				{
					Rotate[i] = rand() % 4 + 1;

					NewX[i] = x[i];
					NewY[i] = y[i];

					switch (Rotate[i])
					{
					case 1:
						if (Map[y[i]][NewX[i] + 1] != 'A')
						{
							NewX[i] += 1;
						}

						break;

					case 2:
						if (Map[y[i]][NewX[i] - 1] != 'A')
						{
							NewX[i] -= 1;
						}

						break;

					case 3:
						if (Map[NewY[i] - 1][x[i]] != 'A')
						{
							NewY[i] -= 1;
						}

						break;

					case 4:
						if (Map[NewY[i] + 1][x[i]] != 'A')
						{
							NewY[i] += 1;
						}

						break;
					}
				}

				Time = 0;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (Map[NewY[i]][NewX[i]] == ' ' || Map[NewY[i]][NewX[i]] == 'B' || Map[NewY[i]][NewX[i]] == 'C')
			{
				if (Map[NewY[i]][NewX[i]] == 'B')
				{
					Map[y[i]][x[i]] = 'B';
				}

				else if (Map[NewY[i]][NewX[i]] == ' ')
				{
					Map[y[i]][x[i]] = ' ';
				}

				else if (Map[NewY[i]][NewX[i]] == 'C')
				{
					Life = false;
				}

				if (i == 0)
				{
					Map[NewY[i]][NewX[i]] = '1';
				}

				if (i == 1)
				{
					Map[NewY[i]][NewX[i]] = '2';
				}

				if (i == 2)
				{
					Map[NewY[i]][NewX[i]] = '3';
				}

				if (i == 3)
				{
					Map[NewY[i]][NewX[i]] = '4';
				}

				x[i] = NewX[i];
				y[i] = NewY[i];
			}

			if (NewY[i] == 9 && (NewX[i] == 0 || NewX[i] == 18))
			{
				if (NewX[i] == 0)
				{
					NewX[i] = 17;
				}

				else
				{
					NewX[i] = 1;
				}

				Map[y[i]][x[i]] = 'B';

				if (i == 0)
				{
					Map[NewY[i]][NewX[i]] = '1';
				}

				if (i == 1)
				{
					Map[NewY[i]][NewX[i]] = '2';
				}

				if (i == 2)
				{
					Map[NewY[i]][NewX[i]] = '3';
				}

				if (i == 3)
				{
					Map[NewY[i]][NewX[i]] = '4';
				}

				x[i] = NewX[i];
				y[i] = NewY[i];
			}
		}
	}
};