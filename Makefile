# Makefile
# Řešení IJC-DU1, příklad a), b) 20.3.2018
# Autor: Jan Havlín, FIT
# Popis: make all			- přeloží primes, primes-i a steg-decode
#		 make primes 		- přeloží primes s makry
#		 make primes-i		- přeloží primes s inline funkcemi
#		 make steg-decode 	- přeloží steg-decode
#		 make run 			- přeloží primes s makry a primes-i s inline funkcemi a spustí time ./primes
#		 make zip 			- zabalí potřebné soubory do .zipu
#		 make clean			- smaže nepotřebné soubory

CFLAGS = -O2 -g -std=c99 -pedantic -Wall -Wextra -lm
CC = gcc

all: primes primes-i steg-decode

eratosthenes.o: eratosthenes.c eratosthenes.h error.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o error.o

ppm.o: ppm.c ppm.h error.h
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o

primes.o: primes.c eratosthenes.h error.h
	$(CC) $(CFLAGS) -c primes.c -o primes.o

primes-i.o: primes.c eratosthenes.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

steg-decode.o: steg-decode.c error.h eratosthenes.h ppm.h
	$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o

primes: primes.o eratosthenes.o error.o
	$(CC) $(CFLAGS) primes.o error.o eratosthenes.o -o primes

primes-i: primes-i.o eratosthenes.o error.o
	$(CC) $(CFLAGS) primes-i.o eratosthenes.o error.o -o primes-i

steg-decode: steg-decode.o eratosthenes.o ppm.o error.o
	$(CC) $(CFLAGS) steg-decode.o error.o eratosthenes.o ppm.o -o steg-decode

run: primes primes-i
	time ./primes	
	time ./primes-i
	
zip:
	zip xhavli47 *.c *.h Makefile

clean:
	rm *.o primes primes-i steg-decode