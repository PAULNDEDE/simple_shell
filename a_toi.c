/**
 * convert_string_to_int -function converts a string to an integer
 * @str: string to be converted to integer
 * Return: integer value of string on success,else -1 on error
 */
int convert_string_to_int(char *str)
{
	int result = 0, index = 0;

	while (str[index])
	{
	if (str[index] < '0' || str[index] > '9')
	return (-1);
	if (str[index] >= '0' || str[index] <= '9')
	result = result * 10 + (str[index] - '0');
	index++;
	}
	return (result);
}
