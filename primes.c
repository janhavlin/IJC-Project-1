// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

#include <stdio.h>
#include "bit_array.h"
#include "eratosthenes.c"


int main()
{	// Zjistit, jestli toto patri do eratosthenes.c
	// puts("Vytvareni bitoveho pole o velikosti 222000000:");
	bit_array_create(pole, 222000000L);
	// bit_array_create(pole, 10000L);
	// puts("Volani Eratosthenes nad timto bitovym polem:");
	Eratosthenes(pole);
	// puts("Vypis vsech prvocisel v poli:");
	
	for (unsigned long i = 0; i < bit_array_size(pole); i++)
	{
		if (bit_array_getbit(pole, i) == 0)
		{
			printf("%lu\n", i);
		}
	}
	return 0;
}