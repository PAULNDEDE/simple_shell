#include "main.h"
/**
 * find_path - finds first executable path
 * of user's first input token
 * @first: first input token
 * Return: first executable path on success
 */
char *find_path(char *first)
{
	int i = 0, j = 0;
	struct stat st;
	char *path = getenv("PATH"), *string = NULL, *pth = NULL;

	pth = strtok(path, ":");
	while (pth)
	{
		string = malloc(strlen(first) + strlen(pth) + 2);
		for (i = 0; pth[i]; i++)
			string[i] = pth[i];
		string[i++] = '/';
		for (j = 0; first[j]; j++)
			string[i + j] = first[j];
		string[i + j] = '\0';
		if (stat(string, &st) == 0)
			return (string);
		pth = strtok(NULL, ":");
		free(string);
	}
	return (NULL);
}
