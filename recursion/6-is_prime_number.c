#include "main.h"

/**
 * prime_helper - checks divisors recursively
 * @n: the number to check
 * @i: current divisor
 *
 * Return: 1 if prime, 0 if not
 */
int prime_helper(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (prime_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: the number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	return (prime_helper(n, 2));
}
