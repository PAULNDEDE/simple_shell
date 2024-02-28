#include "main.h"
/**
 * hand_hash - handles # command
 * @str: untokenized user input
 * Return: user input upto first # occurrence
 */
char *hand_hash(char *str)
{
	char *str2;

	str2 = strtok(str, "#");
	return (str2);
}
