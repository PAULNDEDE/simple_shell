#include "main.h"
/**
 * hash_handler - function  handles the  # command
 * @str:user input (untokenized)
 * Return: user input until # appears
 */
char *hash_handler(char *str)
{
	char *str2;

	str2 = strtok(str, "#");
	return (str2);
}
