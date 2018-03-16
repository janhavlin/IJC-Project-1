CFLAGS = -g -std=c99 -pedantic -Wall -Wextra -lm

test:
	#gcc tests.c -o tests -O2 -std=c99 -Wall -pedantic -g -lm
	gcc tests.c -o tests $(CFLAGS)
	./tests
	
prime:
	# gcc primes.c -o primes -O2 $(CFLAGS)
	gcc -DUSE_INLINE primes.c -o primes-i -O2 $(CFLAGS)
	
ppm:
	gcc steg-decode.c -o steg-decode -O2 $(CFLAGS)
clean:
	-rm tests