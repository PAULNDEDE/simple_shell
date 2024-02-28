#include "main.h"
/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int count = 0;
	ssize_t i = 0;
	size_t n = 0;
	char *buf = NULL;

	if (argc < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		count++;
		buf = NULL;
		signal(SIGINT, control);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		i = getline(&buf, &n, stdin);
		if (i == -1)
		{
			free(buf);
			exit(0);
		}
		if (buf[0] != '\n')
		{
			if (buf[0] != '#')
			{
				buf = hand_hash(buf);
				toker(buf, argv, count);
			}
			free(buf);
		}
		else
			free(buf);
	}
	return (0);
}
