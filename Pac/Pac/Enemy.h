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
	int newx[4] = { 0 , 0 , 0, 0 }, newy[4] = { 0, 0, 0, 0 };
	int rotate[4] = { 1, 1, 1, 1 }, ti = 0;

	void update() {
		ti++;

		if (ti >= 300) 
		{
			for (int i = 0; i < 4; i++)
			{
				rotate[i] = rand() % 4 + 1;

				newx[i] = x[i];
				newy[i] = y[i];

				switch (rotate[i])
				{
				case 1:
					if (TileMap[y[i]][newx[i] + 1] != 'A')
					{
						newx[i] += 1;
					}

					break;

				case 2:
					if (TileMap[y[i]][newx[i] - 1] != 'A')
					{
						newx[i] -= 1;
					}

					break;

				case 3:
					if (TileMap[newy[i] - 1][x[i]] != 'A')
					{
						newy[i] -= 1;
					}

					break;

				case 4:
					if (TileMap[newy[i] + 1][x[i]] != 'A')
					{
						newy[i] += 1;
					}

					break;
				}
			}

			ti = 0;
		}

		for (int i = 0; i < 4; i++) 
		{
			if (TileMap[newy[i]][newx[i]] == ' ' || TileMap[newy[i]][newx[i]] == 'B' || TileMap[newy[i]][newx[i]] == 'C')
			{
				if (TileMap[newy[i]][newx[i]] == 'B')
				{
					TileMap[y[i]][x[i]] = 'B';
				}

				else if (TileMap[newy[i]][newx[i]] == ' ')
				{
					TileMap[y[i]][x[i]] = ' ';
				}

				else if (TileMap[newy[i]][newx[i]] == 'C')
				{ 
					life = false;
				}

				if (i == 0)
				{
					TileMap[newy[i]][newx[i]] = '1';
				}

				if (i == 1)
				{ 
					TileMap[newy[i]][newx[i]] = '2';
				}

				if (i == 2)
				{
					TileMap[newy[i]][newx[i]] = '3';
				}

				if (i == 3)
				{
					TileMap[newy[i]][newx[i]] = '4';
				}

				x[i] = newx[i];
				y[i] = newy[i];
			}

			if (newy[i] == 9 && (newx[i] == 0 || newx[i] == 18))
			{
				if (newx[i] == 0)
					newx[i] = 17;

				else
					newx[i] = 1;

				TileMap[y[i]][x[i]] = 'B';

				if (i == 0)
				{
					TileMap[newy[i]][newx[i]] = '1';
				}

				if (i == 1)
				{
					TileMap[newy[i]][newx[i]] = '2';
				}

				if (i == 2)
				{
					TileMap[newy[i]][newx[i]] = '3';
				}

				if (i == 3)
				{
					TileMap[newy[i]][newx[i]] = '4';
				}

				x[i] = newx[i];
				y[i] = newy[i];
			}
		}
	}
};