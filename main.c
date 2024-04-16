#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "shell.h"

// Main function to check if the shell is running or not
int main(void)
{
    // Determine if fs linked to a terminal
    if (isatty(STDIN_FILENO) == 1)
    {
        shell();
    }
    else
    {
        noshell();
    }
    return 0;
}
