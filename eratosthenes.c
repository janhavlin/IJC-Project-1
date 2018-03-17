// eratosthenes.c
// Řešení IJC-DU1, příklad a), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

// Merlin: ne-inline: 11s, inline: 10s

// ne-inline
// real    2m5.583s
// user    0m16.282s
// sys     0m49.325s

// inline
// real    2m0.117s
// user    0m16.669s
// sys     0m49.138s

#include <math.h>
#include "bit_array.h"

// bit_array_create(pole, 222000000L);

void Eratosthenes(bit_array_t pole)
{
	bit_array_setbit(pole, (unsigned long)0, (unsigned long)1);	// Nastaveni indexu 0 a 1 (nejsou prvocisla)
	bit_array_setbit(pole, 1, 1);
	for (unsigned long i = 2; i < (unsigned long)sqrt(bit_array_size(pole)); i++)
	{
		for (unsigned long j = 2; j*i < bit_array_size(pole); j++)
		{
			bit_array_setbit(pole, j*i, 1);
		}
	}
}