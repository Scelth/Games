#pragma once
#include <SFML/Graphics.hpp>

class Score 
{
public:
	Sprite sec[3];
	int s[3], c;
	bool vid[3];

	Score(Texture& image) 
	{
		for (int i = 0; i < 3; i++) 
		{
			sec[i].setTexture(image);

			sec[i].setPosition(10 + 22 * i, H * Split + 10);

			sec[i].setTextureRect(IntRect(0, 0, 22, 45));

			s[i] = 0;
			c = 0;
		}
	}

	void Update() 
	{
		if (c < 10) 
		{
			s[0] = c;

			vid[0] = true;
			vid[1] = false;
			vid[2] = false;
		}

		else if (c >= 10 && c < 100) 
		{
			s[0] = c / 10;
			s[1] = c % 10;

			vid[0] = true;
			vid[1] = true;
			vid[2] = false;
		}

		else if (c >= 100 && c < 1000)
		{
			s[0] = c / 100;
			s[1] = (c / 10) % 10;
			s[2] = (c % 100) % 10;

			vid[0] = true;
			vid[1] = true;
			vid[2] = true;
		}

		for (int i = 0; i < 3; i++)
		{
			sec[i].setTextureRect(IntRect(22 * s[i], 0, 22, 45));
		}
	}
};