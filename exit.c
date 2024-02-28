#include "main.h"
/**
 * exit_fxn - exits program
 * @tks: tokenized user input
 * @tk: untokenized user input
 * Return: Nothing
 */
void exit_fxn(char **tks, char *tk)
{
	int e_val = 0, i = 0;

	if (tks[1] != NULL)
		e_val = a_toi(tks[1]);

	free(tk);
	for (i = 0; tks[i]; i++)
		free(tks[i]);
	free(tks);
	exit(e_val);
}
