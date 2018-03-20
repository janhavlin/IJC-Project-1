// steg-decode.c
// Řešení IJC-DU1, příklad b), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 6.4.0
// Popis: Dešifrování tajné zprávy

#include <stdio.h>
#include <stdlib.h>
#include "eratosthenes.h"
#include "ppm.h"
#include "bit_array.h"
#include "error.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
		error_exit("Nebyl zadan vstupni soubor.\n");

	struct ppm* img = ppm_read(argv[1]);
	if (img == NULL)
	{
		error_exit("Chyba pri cteni souboru.\n");
	}
	
	// Limit 3*1000*1000 ze zadani, abychom mohli staticky alokovat pole
	bit_array_create(pole, 3000000L);
	Eratosthenes(pole);
	
	int n = 0;
	char tmp_byte = 0;
	for (unsigned long i = 11; i < bit_array_size(pole) && i < (3 * img->xsize * img->ysize); i++)
	{
		if (bit_array_getbit(pole, i) == 0)
		{
			char tmp_bit = img->data[i];
			tmp_bit &= 1;
			tmp_bit = tmp_bit << n;
			tmp_byte |= tmp_bit;

			// Nacteni 8 bitu, vypis charu, pripadne exit pri '\0'
			if (n == 7)
			{
				if (tmp_byte == '\0')
				{
					free(img);
					return 0;
				}
				else
				{
					printf("%c", tmp_byte);
				}
				
				// Vynulovani hodnot pro dalsi iteraci jednoho bytu
				n = 0;
				tmp_byte = 0;
			}
			else
				n++;
		}
	}
	free(img);
	return 1;
}