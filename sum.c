#include <stdio.h>

/**
 * main - Entry point of the program
 *
 *Description: The function calculates the sum of numbers between 1 and 10
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int sum = 0;
	int a;

	for (a = 1; a <= 10; a++)
	{
	sum += a;
	}

	printf("The sum is: %d\n", sum);
	return (0);
}
