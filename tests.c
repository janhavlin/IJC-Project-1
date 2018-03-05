#include <stdio.h>
#include "bit_array.h"
#include "eratosthenes.c"
bit_array_create(pole_prime, 10000L);

// void Eratosthenes(bit_array_t pole)
// {
	// bit_array_setbit(pole, 0, 1);
	// bit_array_setbit(pole, 1, 1);
	// for (int i = 2; i <	sqrt(100); i++)
	// {
		// for (int j = 2; j*i < bit_array_size(pole_prime); j++)
		// {
			// bit_array_setbit(pole, j*i, 1);
		// }
	// }
// }

int main(int argc, char *argv[])
{
	puts("Vytvareni bitoveho pole o 100 bitech");
	bit_array_create(pole, 100L);//pole, 100);
	bit_array_create(pole1, 10000L);//pole, 100);	
	
	printf("Test get_array_size, expected: 100, got: %lu\n", bit_array_size(pole));	
	printf("Test get_array_size, expected: 10000, got: %lu\n", bit_array_size(pole1));	

	puts("\n********* TESTOVANI VELIKOSTI POLE *********");
	printf("Test pole size, expected: 3, got: %lu\n", sizeof(pole)/sizeof(pole[0]));	
	printf("Test pole1 size, expected: 158, got: %lu\n", sizeof(pole1)/sizeof(pole1[0]));	
	
	puts("\n********* PRIDAVANI BITU DO POLE *********");
 	int values[] = {0, 2, 5, 8, 12, 18, 26, 33, 64, 65, 91};
	for (int i = 0; i < 11; i++)
	{
		printf("Nastavuju %d. index na 1\n", values[i]); bit_array_setbit(pole, values[i], 1);
	}
	for (int i = 0; i < 11; i++)
	{
		printf("%d. index expected: 1, got: %d\n", values[i], bit_array_getbit(pole, values[i]));
	}
	
	printf("\nExpected 1 na indexech: 0, 2, 5, 8, 12, 18, 26, 33, 64, 65, 91\n");
	for (int i = 0; i < 100; i++)
	{
		printf("%d: %d\n", i, bit_array_getbit(pole, i));
	} 

	puts("\n********* ODEBIRANI BITU Z POLE *********");
 	int values_delete[] = {0, 2, 5, 8, 12, 18, 26, 33, 64, 65, 91};
	puts("Nastavuju vsechny bity na 1");
	for (int i = 0; i < 100; i++)
	{
		bit_array_setbit(pole, i, 1);
	} 
	for (int i = 0; i < 11; i++)
	{
		printf("Nastavuju %d. index na 0\n", values_delete[i]); bit_array_setbit(pole, values_delete[i], 0);
	}
	printf("\n\nExpected 0 na indexech: 0, 2, 5, 8, 12, 18, 26, 33, 64, 65, 91\n");
	for (int i = 0; i < 100; i++)
	{
		printf("%d: %d\n", i, bit_array_getbit(pole, i));
	}

	puts("\n********* OVERFLOW TEST *********");
	printf("Nastavuju %d. index na 1, expected: OVERFLOW ERROR, got: ", 100); bit_array_setbit(pole, 100, 1);	
	printf("Ziskavam %d. index, expected: OVERFLOW ERROR, got: ", 100); bit_array_getbit(pole, 100);
	
	puts("\n********* ERATOSTHENES TEST *********");
	// puts("Tisk noveho pole:");
	// for (int i = 0; i < bit_array_size(pole_prime); i++)
	// {
		// printf("%d: %d\n", i, bit_array_getbit(pole_prime, i));
	// }
	
	Eratosthenes(pole_prime);puts("\nZavolani Eratosthenes()");
	
	// puts("\nTISK CELEHO POLE:");
	// for (int i = 0; i < bit_array_size(pole_prime); i++)
	// {
		// printf("%d: %d\n", i, bit_array_getbit(pole_prime, i));
	// }
	
	puts("\nTISK PRVOCISEL:");
	for (int i = 0; i < bit_array_size(pole_prime); i++)
	{
		if (bit_array_getbit(pole_prime, i) == 0)
			printf("%d ", i);
	}
	return 0;
	}
