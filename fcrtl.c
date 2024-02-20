 #include <stdio.h>

/**
 * fctrl - function calculates the factorial of a number
 * @a: The number whose factorial is to be calculated
 *
 * Return: The factorial of a
 */
unsigned int fctrl(unsigned int a)
{
	if (a == 0 || a == 1)
		return (1);
	else
		return (a * fctrl(n - 1));
}
