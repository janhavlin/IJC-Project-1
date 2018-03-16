// ppm.c
// Řešení IJC-DU1, příklad b), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"

struct ppm * ppm_read(const char * filename)
{
	int c;
	FILE *file;
	file = fopen(filename, "r");
	if (file)
	{
		if ((c = getc(file)) == 'P' && (c = getc(file)) == '6' && (c = getc(file)) == '\n')
		{

			char tmp_str[32];
			fgets(tmp_str, 32, file);
			// puts(tmp_str);
			struct ppm* img;
			img = (struct ppm *)malloc(sizeof(struct ppm));
			sscanf(tmp_str, "%u %u\n", &(img->xsize), &(img->ysize));

			// img->data = (char*)malloc(sizeof(char) * 3 * img->xsize * img->ysize);
			// puts("BLABLA");
			// printf("%u %u\n", img->xsize, img->ysize);
			
			if ((c = getc(file)) == '2' && (c = getc(file)) == '5' && (c = getc(file)) == '5' && (c = getc(file)) == '\n')
			{
				// puts("BLABLABLA");
				unsigned i = 0;
				while ((c = getc(file)) != EOF && i < 3 * img->xsize * img->ysize 
						&& i < 100000)	// TOTO SMAZAT
				{
					// printf("%u ", i);
					//putchar(c);
					img->data[i] = c;
					// putchar(img->data[i]);
					i++;
				}
				return img;
			}
			else
			puts("ERROR");				
		}
		else
		puts("ERROR");
		// while ((c = getc(file)) != '5')
			// putchar(c);
		// fclose(file);
	}
	puts("ERROR");
	return NULL;
}

// int main(int argc, char *argv[])
// {
// if (argc){};
	// ppm_read(argv[1]);
	// return 0;
// }