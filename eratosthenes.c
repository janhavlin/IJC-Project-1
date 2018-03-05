// eratosthenes.c.h
// Řešení IJC-DU1, příklad a), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

#include <stdio.h>
#include <math.h>
#include "bit_array.h"

bit_array_create(pole, 222000000L);

void Eratosthenes(bit_array_t pole)
{
	bit_array_setbit(pole, 0, 1);
	bit_array_setbit(pole, 1, 1);
	for (int i = 2; i <	sqrt(bit_array_size(pole)); i++)
	{
		for (int j = 2; j*i < bit_array_size(pole); j++)
		{
			bit_array_setbit(pole, j*i, 1);
		}
	}
}