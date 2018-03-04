test:
	gcc tests.c -o tests -Wall -g
	./tests
clean:
	-rm tests