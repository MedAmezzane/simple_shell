#include "shell.h"

/**
 * execute_command - Execute a given command.
 *
 * @parsed_command: An array of strings representing the command and its
 * arguments.
 * @argv: An array of strings representing the program's arguments.
 *
 * Return: The exit status of the executed command.
 */
int execute_command(char **parsed_command, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(parsed_command[0], parsed_command, environ) == -1)
		{
			perror(argv[0]);
			free2DArray(parsed_command);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free2DArray(parsed_command);
	}
	return (WEXITSTATUS(status));
}
