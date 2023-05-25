#include "main.h"

void free_arry(char **ar)
{
    int i = -1;

    while(ar[++i])
        free(ar[i]), ar[i] = NULL;
    free(ar);
}

/**
 * my_printf - print a string to stander out put
 * @str: string input
 * Return: void
 */
void my_printf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}