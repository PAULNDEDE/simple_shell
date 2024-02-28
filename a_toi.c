/**
 * a_toi - converts a stirn to an integer
 * @str: string to convert to integer
 * Return: integer value of str on success
 * -1 on error
 */
int a_toi(char *str)
{
	int val = 0, i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (str[i] >= '0' || str[i] <= '9')
			val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val);
}
