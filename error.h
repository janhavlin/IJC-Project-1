// error.h
// Řešení IJC-DU1, příklad a), b), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 6.4.0
// Popis: Funkce pro chybové stavy

#ifndef ERROR_H_
#define ERROR_H_

void warning_msg(const char *fmt, ...);

void error_exit(const char *fmt, ...);

#endif // ERROR_H_