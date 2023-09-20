#include "main.h"

/**
 * custom_exit - Function to handle custom shell program termination.
 * @arg: Array of strings representing command line with arguments.
 * @line: The user input command.
 * @status: Exit status for the shell program.
 */
void custom_exit(char *arg[], char *line, int status)
{
	if (arg[1])
	{
		if (valid_exit(arg[1]))
		{
			status = atoi(arg[1]);
		}
		else
		{
			fprintf(stderr, "./shell: exit: invalid exit code: %s\n", arg[1]);
			status = 2;
		}
	}
	else if (status == -1)
	{
		status = EXIT_SUCCESS;
	}

	free(line);
	exit(status);
}
/**
 * valid_exit - checks if the argument is a valid exit code or not
 * @arg: argument
 * Return: 1 if it's a valid exit code, 0 otherwise
 */
int valid_exit(char *arg)
{
	if (arg[0] != '-' && is_numeric(arg))
		return (1);
	else
		return (0);
}
