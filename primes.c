// primes.c
// Řešení IJC-DU1, příklad a), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

#include <stdio.h>
#include "bit_array.h"
#include "eratosthenes.c"


int main()
{	// Zjistit, jestli toto patri do eratosthenes.c
	puts("bla1\n");
	bit_array_create(pole, 222000000L);
	// bit_array_create(pole, 10000L);
	puts("bla2\n");
	Eratosthenes(pole);
	puts("bla3\n");
	
	for (unsigned long i = 0; i < bit_array_size(pole); i++)
	{
		if (bit_array_getbit(pole, i) == 0)
		{
			printf("%lu\n", i);
		}
	}
	return 0;
}