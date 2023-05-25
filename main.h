#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

/**
 * cmd_t - data stracut.
 * @av: input arrays od string.
 * @cmd: input string.
 */
typedef struct cmd_t
{
	char **av;
	char *cmd;
	char *name;
} cmd_t;


void free_arry(char **ar);
void my_printf(const char *str);
void _split(cmd_t *cmd);
void remove_spaces(char *s);
void cmd_init(cmd_t *cmd, char *name);

#endif