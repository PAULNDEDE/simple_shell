#include "main.h"

/**
 * handle_signl -function handles signal
 * @signl:user input signal
 * Return: void
 */
void handle_signl(int signl)
{
	(void)signl;
	write(STDOUT_FILENO, "\n$ ", 3);
}
