#include "simple_shell.h"

/**
 * parse_and_execute - Does the parsing and execution of the entered commands
 *
 * @src: Pointer to the structure of the entered command
 *
 * Return: 1 (Continue with program)
 */


int parse_and_execute(struct scanner_s *src)
{
	skip_white_spaces(src);

	struct token_s *tok = tokenize(src);

	if (tok == &eof_token)
	{
		return (0);
	}

	while (tok && tok != &eof_token)
	{
		struct node_s *cmd = parse_simple_command(tok);

		if (!cmd)
		{
			break;
		}

		do_simple_command(cmd);
		free_node_tree(cmd);
		tok = tokenize(src);
	}

	return (1);
}
