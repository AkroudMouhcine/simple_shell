#include "main.h"

/**
 * is_exit - exit.
 * @cmd: input cmd_t.
 * @exitstatus: input int.
 *
 * Return: void
 */
void is_exit(cmd_t *cmd, int exitstatus)
{
	if (!strcmp(cmd->av[0], "exit"))
	{
		if (cmd->av[1])
			exitstatus = atoi(cmd->av[1]);
		if (exitstatus == -1 && !cmd->av[1])
			exitstatus = EXIT_SUCCESS;
		free(cmd->cmd);
		free_arry(cmd->av);
		exit(exitstatus);
	}
	if (!strcmp(cmd->av[0], "env"))
		print_env();
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

	nread = getline(&cmd->cmd, &n, stdin);
	if (nread == -1)
	{
		free(cmd->cmd);
		exit(EXIT_SUCCESS);
	}
	cmd->cmd[nread - 1] = '\0';
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

