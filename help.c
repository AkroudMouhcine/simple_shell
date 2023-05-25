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


void _split(cmd_t *cmd)
{
    char *tkn;
    int ntkn =0;

    cmd->av = malloc(2 * sizeof(char *));
    if (cmd->av == NULL)
    {
        free(cmd->cmd);
        perror(cmd->name);
        exit(EXIT_SUCCESS);
    }
    cmd->av[0] = NULL;
    cmd->av[1] = NULL;
    tkn = strtok(cmd->cmd, " ");
    while (tkn)
    {
        cmd->av = realloc(cmd->av, (ntkn + 2) * sizeof(char *));
        if (cmd->av == NULL)
        {
            free_arry(cmd->av);
            free(cmd->cmd);
            perror(cmd->name);
            exit(EXIT_FAILURE);
        }
        cmd->av[ntkn] = strdup(tkn);
        if (cmd->av[ntkn]  == NULL)
        {
            free_arry(cmd->av);
            free(cmd->cmd);
            perror(cmd->name);
            exit(EXIT_FAILURE);
        }
        ntkn++;
        tkn = strtok(NULL, " ");
    }
    cmd->av[ntkn] = NULL;
}