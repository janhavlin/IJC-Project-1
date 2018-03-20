// ppm.h
// Řešení IJC-DU1, příklad b), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 6.4.0
// Popis: Funkce pro čtení a zápis do souboru formátu .ppm

#ifndef PPM_H_
#define PPM_H_

struct ppm {
        unsigned xsize;
        unsigned ysize;
        char data[];    // RGB bajty, celkem 3*xsize*ysize
};

// načte obsah PPM souboru do touto funkcí dynamicky
// alokované struktury. Při chybě formátu použije funkci warning_msg
// a vrátí NULL.  Pozor na "memory leaks".
struct ppm * ppm_read(const char * filename);

// zapíše obsah struktury p do souboru ve formátu PPM.
// Při chybě použije funkci warning_msg a vrátí záporné číslo.
int ppm_write(struct ppm *p, const char * filename);

#endif	//PPM_H_