// error.c
// Řešení IJC-DU1, příklad a), b), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "error.h"

void warning_msg(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
    va_list arg;
    va_start(arg, fmt);
    vfprintf(stderr, fmt, arg);
    va_end(arg);
}

void error_exit(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
    va_list arg;
    va_start(arg, fmt);
    vfprintf(stderr, fmt, arg);
    va_end(arg);
	exit(1);
}