#include "main.h"

/*
int _getenv(char *key)
{
	char *token;
	unsigned int i = 0;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(key, token) == 0)
			return (1);
	}
	return (0);
}
*/

void _setenv(char *key, char *value, int overwrite)
{
	setenv(key, value, overwrite);
}

void _unsetenv(char *key)
{
	unsetenv(key);
}
