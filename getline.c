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
	static char buffer[BUFFER_SIZE];
	static ssize_t buffer_index;
	static ssize_t bytes_read;
	size_t line_length = 0;
	char *line = NULL;
	char current_char;

	while (1)
	{
		if (buffer_index >= bytes_read)
		{
			bytes_read = read(fileno(stream), buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (bytes_read <= 0)
				break;
		}
		current_char = buffer[buffer_index++];
		if (current_char == '\n' || current_char == '\0')
		{
			if (*n < ++line_length)
			{
				*n = line_length;
				line = realloc(line, *n);
			}
			line[line_length - 1] = '\0';
			break;
		}
		else
		{
			line_length++;
			if (*n < line_length)
			{
				*n = line_length * 2;
				line = realloc(line, *n);
			}
			line[line_length - 1] = current_char;
		}
	}
	*lineptr = line;
	return (line_length == 0 ? -1 : (ssize_t)line_length);
}
