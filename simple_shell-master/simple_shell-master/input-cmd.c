#include "main.h"
/**
 * get_type_cmd - determines the type of command line based on input
 * @line: user input command
 * Return: depend
 */
int get_type_cmd(const char *line)
{
	if (strcmp(line, "env") == 0)
	{
		return (COMMAND_ENV); /* exit with a status */
	}
	else if (strcmp(line, "exit") == 0)
	{
		return (COMMAND_EXIT); /* exit with a status */
	}
	else
	{
		if (strcmp(line, "custom") == 0)
		{
			return (COMMAND_CUSTOM); /* exit with a status */
		}
		return (0);
	}
}
/**
 * read_cmd - eads a line of input from the user
 * @line: input command
 * @len: length
 * Return: input
 */
ssize_t read_cmd(char **line, size_t *len)
{
	ssize_t R = 0;

	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}
	R = getline(line, len, stdin);
	if (R == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			return (-1);
		}
		free(line);
		exit(EXIT_FAILURE);
	}
	return (R);
}
