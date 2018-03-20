// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 6.4.0
// Popis: Tisk prvočísel od 0 do 220 milionů

#include <stdio.h>
#include <stdlib.h>
#include "bit_array.h"
#include "eratosthenes.h"

int main()
{
	bit_array_create(pole, 222000000L);

	Eratosthenes(pole);
	
	for (unsigned long i = 0; i < bit_array_size(pole); i++)
	{
		if (bit_array_getbit(pole, i) == 0)
		{
			printf("%lu\n", i);
		}
	}
	return 0;
}