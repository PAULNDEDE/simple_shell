#include "main.h"
/**
 * control - handles control + C
 * @n: input signal
 * Return: nothing
 */
void control(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}
