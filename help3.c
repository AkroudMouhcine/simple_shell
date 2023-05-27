#include "main.h"
/**
 * _setenv - Entry point.
 * @key: key value.
 * @value: value.
 * @overwrite: overwrite.
 *
 * Return: Always 0.
 */
void _setenv(char *key, char *value, int overwrite)
{
	setenv(key, value, overwrite);
}

/**
 * _unsetenv - Entry point.
 * @key: key value.
 * Return: Always 0.
 */
void _unsetenv(char *key)
{
	unsetenv(key);
}

/**
 * find_path - find path.
 * @cmd: input cmd_t.
 * Return: int.
 */
int find_path(cmd_t *cmd)
{
	const char *path = getenv("PATH");
	char *token, *search_path;
	char executable_path[4096];
	int find = -1;

	if (!path)
		return (-1);
	search_path = strdup(path);
	if (!search_path)
		return (-1);
	token = strtok(search_path, ":");
	while (token)
	{
		strcpy(executable_path, token);
		strcat(executable_path, "/");
		strcat(executable_path, cmd->av[0]);
		if (access(executable_path, X_OK) == 0)
		{
			free(cmd->av[0]);
			cmd->av[0] = strdup(executable_path);
			find = 0;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(search_path);
	return (find);
}
