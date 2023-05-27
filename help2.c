#include "main.h"

/**
 * built_in - built in functions.
 * @cmd: input cmd_t.
 * @exitstatus: input int.
 *
 * Return: int
 */
int built_in(cmd_t *cmd, int exitstatus)
{
	if (!strcmp(cmd->av[0], "exit"))
	{
		my_exit(cmd, exitstatus);
	}
	else if (!strcmp(cmd->av[0], "env"))
	{
		print_env();
		return (1);
	}
	else if (!strcmp(cmd->av[0], "setenv") && cmd->av[1])
	{
		_setenv(cmd->av[1], cmd->av[2], 1);
		return (1);
	}
	else if (!strcmp(cmd->av[0], "unsetenv") && cmd->av[1])
	{
		_unsetenv(cmd->av[1]);
		return (1);
	}
	return (0);
}

/**
 * get_cmd - get cmd.
 * @cmd: input cmd_t.
 *
 * Return: void
 */
void get_cmd(cmd_t *cmd)
{
	size_t n = 0;
	ssize_t nread;

	nread = _getline(&cmd->cmd, &n, stdin);
	if (nread == -1)
	{
		free(cmd->cmd);
		exit(EXIT_SUCCESS);
	}
	cmd->cmd[nread - 1] = '\0';
	comment(cmd->cmd);
	remove_spaces(cmd->cmd);
}

/**
 * print_env - prints environments
 *
 * Return: void
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		my_printf(environ[i]);
		my_printf("\n");
	}
}

/**
 * my_exit - exit
 * @cmd: input cmd_t
 * @exitstatus: input int
 * Return: void
 */
void my_exit(cmd_t *cmd, int exitstatus)
{
	const char *err = "./hsh: 1: exit: Illegal number: ";

	if (cmd->av[1])
	{
		if (cmd->av[1][0] != '-' && _isanumber(cmd->av[1]))
			exitstatus = atoi(cmd->av[1]);
		else
		{
			write(STDERR_FILENO, err, strlen(err));
			write(STDERR_FILENO, cmd->av[1], strlen(cmd->av[1]));
			write(STDERR_FILENO, "\n", 1);
			exitstatus = 2;
		}
	}
	if (exitstatus == -1 && !cmd->av[1])
		exitstatus = EXIT_SUCCESS;
	free(cmd->cmd);
	free_arry(cmd->av);
	exit(exitstatus);
}

/**
 * comment - handel comment.
 * @str: input string.
 *
 * Return: void
 */
void comment(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[0] == '#' || (str[i] == '#' && str[i - 1] == ' '))
		{
			str[i] = '\0';
			break;
		}
	}
}
