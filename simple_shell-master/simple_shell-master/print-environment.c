#include "main.h"

/**
 * print_environment - Prints all environment variables in the program.
 */
void print_environment(void)
{
	char **env = environ;
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}


/**
 * parse_input - Parses a string into separate arguments by splitting
 * it using whitespace characters (spaces and newline characters).
 * @input_line: A pointer to a string that stores the user input command.
 * @arguments: A pointer to an array of strings where the parsed command
 * arguments will be stored.
 * Return: The number of tokens (arguments) found.
 */
int parse_input(char *input_line, char **arguments)
{
	int num_tokens = 0;
	char *token = strtok(input_line, " \n");

	while (token != NULL && num_tokens < 10)
	{
		arguments[num_tokens] = token;
		num_tokens++;
		token = strtok(NULL, " \n");
	}

	arguments[num_tokens] = NULL;

	return (num_tokens);
}
