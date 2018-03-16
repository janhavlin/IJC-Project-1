// bit_array.h
// Řešení IJC-DU1, příklad a), 20.3.2018
// Autor: Jan Havlín, FIT
// Přeloženo: gcc 7.1

#ifndef BIT_ARRAY_H_
#define BIT_ARRAY_H_

typedef unsigned long bit_array_t[];

#define GET_INDEX(index) 1 + index/(sizeof(unsigned long)*8)
#define GET_SHIFT(index) (index % (sizeof(unsigned long)*8))

#define bit_array_create(jmeno_pole, velikost) unsigned long jmeno_pole[GET_INDEX(velikost) + !!GET_SHIFT(velikost)] = {(unsigned long)velikost, 0}

#define bit_array_size(jmeno_pole) (jmeno_pole[0])


#define SETBIT_DECIDE(jmeno_pole, index, vyraz) ((vyraz == 0L) ? SETBIT_ZERO(jmeno_pole, index) : SETBIT_ONE(jmeno_pole, index))
#define SETBIT_ZERO(jmeno_pole, index) (jmeno_pole[GET_INDEX(index)] &= ~((unsigned long)1 << GET_SHIFT(index)))
#define SETBIT_ONE(jmeno_pole, index) (jmeno_pole[GET_INDEX(index)] |= ((unsigned long)1 << GET_SHIFT(index)))

#define bit_array_setbit(jmeno_pole, index, vyraz) ((index >= bit_array_size(jmeno_pole)) ? puts("OVERFLOW ERROR") : SETBIT_DECIDE(jmeno_pole, index, vyraz))

#ifndef USE_INLINE

#define GETBIT_GET(jmeno_pole, index) (!!((jmeno_pole[GET_INDEX(index)]) & ((unsigned long)1 << GET_SHIFT(index))))

#define bit_array_getbit(jmeno_pole, index) ((index >= bit_array_size(jmeno_pole)) ? puts("OVERFLOW ERROR") : GETBIT_GET(jmeno_pole, index))

#else

inline void bit_array_setbit(bit_array_t jmeno_pole, unsigned long index, unsigned long vyraz)
{
	if (index >= bit_array_size(jmeno_pole)
	{
		puts("OVERFLOW ERROR");
	}
	else if(vyraz == 0)
	{
		jmeno_pole[GET_INDEX(index)] &= ~((unsigned long)1 << GET_SHIFT(index));
	}
	else
	{
		jmeno_pole[GET_INDEX(index)] |= ((unsigned long)1 << GET_SHIFT(index));
	}
}

inline unsigned long bit_array_getbit(bit_array_t jmeno_pole, unsigned long index)
{
	if (index >= bit_array_size(jmeno_pole))
	{
		puts("OVERFLOW ERROR");
	}
	else
	{
		return !!((jmeno_pole[GET_INDEX(index)]) & ((unsigned long)1 << GET_SHIFT(index)));
	}
	return -1;
}

#endif // USE_INLINE

#endif // BIT_ARRAY_H_