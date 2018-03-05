test:
	gcc tests.c -o tests -O2 -std=c99 -Wall -pedantic -g -lm
	./tests
clean:
	-rm tests