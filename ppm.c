// ppm.c
// Řešení IJC-DU1, příklad b), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "error.h"

/*
struct ppm * ppm_read(const char * filename)
{
	int c;
	FILE *file;
	file = fopen(filename, "r");
	if (file)
	{
		// Cteni po jednotlivych znacich je ponekud osklive, ale pro 8 znaku se to da prezit
		if ((c = getc(file)) == 'P' && (c = getc(file)) == '6' && (c = getc(file)) == '\n')
		{
			unsigned tmp_x, tmp_y;
			
			// Nacteni hodnot X, Y 
			fscanf(file, "%u %u", &tmp_x, &tmp_y);
			struct ppm* img;
			img = (struct ppm *)malloc(sizeof(struct ppm) + 3 * tmp_x * tmp_y);
			
			if (img == NULL)
			{
				fclose(file);	
				error_exit("Alokovani pameti pro strukturu obrazku.\n");	
			}
			
			img->xsize = tmp_x;
			img->ysize = tmp_y;

			if ((c = getc(file)) == '\n' && (c = getc(file)) == '2' && (c = getc(file)) == '5' && (c = getc(file)) == '5' && (c = getc(file)) == '\n')
			{
				unsigned i = 0;
				while ((c = getc(file)) != EOF && i < 3 * img->xsize * img->ysize)
				{
					// printf("%u ", i);
					//putchar(c);
					img->data[i] = c;
					// putchar(img->data[i]);
					i++;
				}
				fclose(file);
				return img;
			} 
			else // Podminka hodnoty barevne hloubky
			{
			free(img);
			fclose(file);	
			warning_msg("PPM soubor neobsahuje barevnou hloubku 255.\n");				
			}
		} 
		else // Podminka prvnich 3 znaku P6\n
		{
		fclose(file);	
		warning_msg("Soubor neni ve formatu P6.\n");
		}

	} // Podminka nacteni souboru (file != NULL)
	else
	{
	warning_msg("Chyba pri cteni souboru.\n");
	}
	return NULL;
}*/

struct ppm * ppm_read(const char * filename)
{
	int c;
	FILE *file;
	file = fopen(filename, "r");
	if (!file)
	{
		warning_msg("Chyba pri otevirani souboru.\n");
		return NULL;
	}

	// Cteni po jednotlivych znacich je ponekud osklive, ale pro 8 znaku se to da prezit
	if ( !((c = getc(file)) == 'P' && (c = getc(file)) == '6' && (c = getc(file)) == '\n') )
	{
		fclose(file);	
		warning_msg("Soubor neni ve formatu P6.\n");
		return NULL;
	}
	
	unsigned tmp_x, tmp_y;
	
	// Nacteni hodnot X, Y 
	fscanf(file, "%u %u", &tmp_x, &tmp_y);
	struct ppm* img;
	img = (struct ppm *)malloc(sizeof(struct ppm) + 3 * tmp_x * tmp_y);
	
	if (img == NULL)
	{
		fclose(file);	
		error_exit("Alokovani pameti pro strukturu obrazku.\n");
		return NULL;
	}
	
	img->xsize = tmp_x;
	img->ysize = tmp_y;

	if ( !((c = getc(file)) == '\n' && (c = getc(file)) == '2' && (c = getc(file)) == '5' && (c = getc(file)) == '5' && (c = getc(file)) == '\n') )
	{
		free(img);
		fclose(file);	
		warning_msg("PPM soubor neobsahuje barevnou hloubku 255.\n");
		return NULL;
	}
	
	unsigned i = 0;
	while ((c = getc(file)) != EOF && i < 3 * img->xsize * img->ysize)
	{
		// printf("%u ", i);
		//putchar(c);
		img->data[i] = c;
		// putchar(img->data[i]);
		i++;
	}
	fclose(file);
	return img;
}

int ppm_write(struct ppm *p, const char * filename)
{
	if (p == NULL)
	{
		warning_msg("Nelze zapisovat do souboru, ukazatel == NULL.\n");
		return -1;
	}
		
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		warning_msg("Chyba pri vytvareni souboru.\n");
		return -1;		
	}
	fprintf(file, "P6\n%u %u\n255\n", p->xsize, p->ysize);
	
	unsigned count = fwrite(p->data, sizeof(char), 3 * p->xsize * p->ysize, file);
	if (count != 3 * p->xsize * p->ysize)
	{
		warning_msg("Chyba pri zapisu do souboru.\n");
		return -1;	
	}
	
	fclose(file);
	return 1;
}