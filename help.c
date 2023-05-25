#include "main.h"

void free_arry(char **ar)
{
    int i = -1;

    while(ar[++i])
        free(ar[i]), ar[i] = NULL;
    free(ar);
}