#include "main.h"

/**
 * _getline - get line.
 * @lineptr: input char **.
 * @n: input size_t.
 * @stream: input FILEL *.
 *
 * Return: void
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}
/**
 * _isanumber - check if number
 * @str: strings to be checked
 * Return: 0 or 1
 */
int _isanumber(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
