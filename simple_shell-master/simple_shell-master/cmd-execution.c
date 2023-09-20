#include "main.h"

/**
 * handle_error - handles execution errors
 *
 * @executable_path: full path that specifies the location
 * of the executable file
 * @arguments: command and its arguments
 * @user_input: user command
 */
void handle_error(char *executable_path, char **arguments, char *user_input)
{
	if (execve(executable_path, arguments, environ) == -1)
	{
		free(executable_path);
		free(user_input);
		perror("Error executing command");
		exit(EXIT_FAILURE);
	}
}


/**
 * execute_command - executes a command by forking a new process
 * @arguments: command and its arguments
 * @executable_path: full path that specifies the location
 * of the executable file
 * @user_input: user command
 * Return: exit status of the executed command or -1 on error
 */
int execute_command(char **arguments, char *executable_path, char *user_input)
{
	pid_t child_pid;

	if (strcmp(arguments[0], "exit") == 0)
	{
		custom_exit(arguments, user_input, 0);
		return (-1);
	}

	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(executable_path, arguments, environ) == -1)
		{
			handle_error(executable_path, arguments, user_input);
			fprintf(stderr, "./shell: %s: command not found\n", user_input);
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		int status;

		waitpid(child_pid, &status, 0);
		free(executable_path);

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));

		fprintf(stderr, "./shell: %s: terminated abnormally\n", user_input);
		return (-1);
	}
	else
	{
		perror("Failed to fork a new process");
		return (-1);
	}
	return (-1);
}
