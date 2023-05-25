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
    cmd.name = argv[0];
    while(1)
    {
        if (isatty(STDIN_FILENO))
            my_printf("#cisfun$ ");
        n = 0;
        nread = getline(&cmd.cmd, &n, stdin);
        if (nread == -1)
        {
            free(cmd.cmd);
            exit(EXIT_SUCCESS);
        }
        cmd.cmd[nread - 1] = '\0';
       _split(&cmd);
       if(strlen(cmd.cmd) != 0 )
       {    
            child_pid = fork();
            if(child_pid == 0)
            {
                if(execve(cmd.av[0], cmd.av, NULL) == -1)
                {
                    perror(cmd.name);
                    free(cmd.cmd);
                    free_arry(cmd.av);
                    exit(1);
                }
            }
            wait(&status);
       }
        free(cmd.cmd);
        free_arry(cmd.av);
    }
    
    return (0);
}