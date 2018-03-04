#include <stdio.h>
#include "bit_array.h"

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
	for (int i = 0; i < 100L; i++)
	{
		printf("%d: %d\n", i, bit_array_getbit(pole, i));
	}

	puts("\n********* OVERFLOW TEST *********");
	printf("Nastavuju %d. index na 1, expected: OVERFLOW ERROR, got: ", 100); bit_array_setbit(pole, 100, 1);	
	printf("Ziskavam %d. index, expected: OVERFLOW ERROR, got: ", 100); bit_array_getbit(pole, 100);
	
	// printf("%d\n", (sizeof(unsigned long)*8));
	// 	// printf("%lu\n", sizeof(int));
	// 		// printf("%d\n", 1 << 65/(sizeof(unsigned long)*8));
	// 			// printf("Nastavuju %d. index na 1\n", 65); bit_array_setbit(pole, 65, 1);
	// 				// printf("%d. index expected: 1, got: %lu\n", 65, bit_array_getbit(pole, 65));
	// 					
	// 						
	// 						/* 	printf("\n\nNastavuju kazdy treti index na 1\n");	
	// 							for (int i = 0; i < 100; i = i + 3)
	// 								{
	// 											bit_array_setbit(pole, i, 1);
	// 												}
	// 													
	// 														for (int i = 0; i < 100; i++)
	// 															{
	// 																	printf("%d: %lu\n", i, bit_array_getbit(pole, i));
	// 																		} */
	// 																			
	return 0;
	}
