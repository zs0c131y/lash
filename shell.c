#include "shell.h"

// UNIX Command Line for shell()
void shell(void)
{
    char *line;
    char **args;
    int status = -1;
    do
    {
        printf("shell> ");       // Print the shell prompt shell> command
        line = read_line();      // Read the command line
        args = split_line(line); // Split the command line into arguments
        status = execute(args);  // Execute the command
        // Avoid memory leaks
        free(line);
        free(args);

        // Exiting with status 0
        if (status > 0)
        {
            exit(status);
        }
    } while (status == -1);
}

// read_line.c
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1) // if getline fails
    {
        if (feof(stdin))
        {
            free(line);         // avoid memory leaks
            exit(EXIT_SUCCESS); // received an EOF
        }
        else
        {
            free(line); // avoid memory leaks if getline fails also
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}

// split_line.c
char **split_line(char *line)
{
    int bufsize = 64;
    int i = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "Shell: Allocation error in shell while splitting lines.\n");
        exit(EXIT_FAILURE);
    }
}