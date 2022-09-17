#include "simple_shell.h"


/**
 * main - Entry point of the simple shell program
 * @argc: Number of arguments int the entered command
 * @argv: Array of pointers to the arguments
 *
 * Return: 0 (Always Success)
 */

int main(int argc, char **argv)
{
	char *my_command;

	init_shell();

	do {
		print_first_prompt();
		my_command = read_command();

		if (!my_command)
		{
			exit(EXIT_SUCCESS);
		}

		if (my_command[0] == '\0' || strcmp(my_command, "\n") == 0)
		{
			free(my_command);
			continue;
		}

		if (strcmp(my_command, "exit\n") == 0)
		{
			free(my_command);
			break;
		}

		struct scanner_s src;

		src.buffer = my_command;
		src.bufsize = strlen(my_command);
		src.charpos = INIT_SRC_POS;

		parse_and_execute(&src);

		free(my_command);

	} while (1);

	exit(EXIT_SUCCESS);
}
