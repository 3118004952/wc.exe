#include "wc.h"


int lines(std::ifstream *fr)
{
	int m = 0;
	char str[256];
	while (fr->getline(str, 256))
	{
		m++;
	}
	return m;
}

int characters(std::ifstream *fr)
{
	int m = 0, n = 0;
	char str[256];
	while (fr->getline(str, 256))
	{
		n = 0;
		while (str[n++] != '\0')
		{
			m++;
		}
	}
	return m;
}

int words(std::ifstream *fr)
{
	int m = 0, n = 0, j = 0;
	char str[256];
	while (fr->getline(str, 256))
	{
		n = 0;
		while (str[n] != '\0')
		{
			if ((str[n] >= 'a' && str[n] <= 'z') || (str[n] >= 'A' && str[n] <= 'Z') || (str[n] >= '0' && str[n] <= '9'))
			{
				j = 1;
			}
			else
			{
				if (j == 1)
				{
					m++;
					j = 0;
				}
			}
			n++;
		}
		if (j == 1)
			m++;
		j = 0;
	}
	return m;
}