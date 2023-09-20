#include "main.h"
/**
 *  shell - function represents the main shell loop it takes
 *  user input processes and executes based on the command type
 */
void shell(void)
{
	char *line = NULL, *arg[10], *path = "/bin/", *full;
	/* line : store user input command*/
	/*arg : store tokenized command arguments path : default path*/
	/*full: store the full path*/
	size_t len = 0;
	ssize_t R;
	/* stores the number of characters read by the read_cmd function */
	int status = -1;

	while ((R = read_cmd(&line, &len)) != -1)
	{
		line[R - 1] = (line[R - 1] == '\n') ? '\0' : line[R - 1];

		if (line[0] == '\0')
			continue;
		if (rm_whitespace(line))
			break;
		switch (get_type_cmd(line))
		{
			case COMMAND_ENV:
				print_environment();
				free(line);
				exit(EXIT_SUCCESS);
				break;
			case COMMAND_EXIT:
				parse_input(line, arg);
				custom_exit(arg, line, status);
				break;
			default:
				parse_input(line, arg);
				_path(arg[0], path, &full);
				status = execute_command(arg, full, line);
				break;
		}
	}

	free(line);
}
/**
 * main - Entry main
 * Return: 0
 */
int main(void)
{
	shell();
	return (0);
}
