#include "main.h"


/**
 * main - Entry point.
 * @argc: is the number of arguments on the command line.
 * @argv: is an array of arguments on the command line.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    cmd_t cmd;
    size_t n = 0;
    ssize_t nread;
    pid_t child_pid = 0;
    int status = 0;

    (void)argc;
    cmd.cmd = NULL;
    cmd.av = NULL;
    while(1)
    {
        printf("#cisfun$ ");
        n = 0;
        nread = getline(&cmd.cmd, &n, stdin);
        if (nread == -1)
        {
            printf("\n");
            free(cmd.cmd);
            exit(1);
        }
        cmd.cmd[nread - 1] = '\0';
        cmd.av = malloc(2 * sizeof(char *));
        cmd.av[0] = strdup(cmd.cmd);
        cmd.av[1] = NULL;
        child_pid = fork();
        if(child_pid == 0)
        {
            if(execve(cmd.cmd, cmd.av, NULL) == -1)
            {
                perror(argv[0]);
                free(cmd.cmd);
                free_arry(cmd.av);
                exit(1);
            }
        }
        wait(&status);
        free(cmd.cmd);
        free_arry(cmd.av);
    }
    
    return (0);
}