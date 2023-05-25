#include "main.h"

/**
 * free_arry - free arry.
 * @ar: an array.
 *
 * Return: void
 */
void free_arry(char **ar)
{
	int i = -1;

	while (ar[++i])
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


/**
 * _split - split cmd.
 * @cmd: input cmd_t.
 *
 * Return: void
 */
void _split(cmd_t *cmd)
{
	char *tkn;
	int ntkn = 0;

	cmd->av = malloc(2 * sizeof(char *));
	if (cmd->av == NULL)
	{
		free(cmd->cmd);
		perror(cmd->name);
		exit(EXIT_SUCCESS);
	}
	cmd->av[0] = NULL;
	cmd->av[1] = NULL;
	remove_spaces(cmd->cmd);
	comment(cmd->cmd);
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


/**
 * remove_spaces - remove spaces from cmd.
 * @s: input string.
 *
 * Return: void
 */
void remove_spaces(char *s)
{
	int i, j, len = strlen(s);

	for (i = 0; i < len && s[i] == ' '; i++)
		;
	for (j = 0; i < len; j++)
	{
		s[j] = s[i];
		i++;
	}
	s[j] = '\0';
	for (i = strlen(s) - 1 ; i > 0 &&  s[i] == ' '; i--)
		s[i] = '\0';
}

/**
 * cmd_init - init cmd.
 * @cmd: input cmd_t.
 * @name: input string.
 *
 * Return: void
 */
void cmd_init(cmd_t *cmd, char *name)
{
	cmd->cmd = NULL;
	cmd->av = NULL;
	cmd->name = name;
}


/**
 * comment - handel comment.
 * @str: input string.
 *
 * Return: void
 */
void comment(char * str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#')
		{
			str[i] = '\0';
			break;
		}
	}
}

