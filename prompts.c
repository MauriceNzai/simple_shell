#include "simple_shell.h"

/**
* print_first_prompt - prints the first prompt for the user to input commands
* Return: nothing
*/
void print_first_prompt(void)
{
	struct symtab_entry_s *entry = get_symtab_entry("PS1");

	if (entry && entry->val)
	{
		fprintf(stderr, "%s", entry->val);
	}
	else
	{
		fprintf(stderr, "Simple_Shell $ ");
	}
}
/**
 * print_second_prompt - Prints prompt incase user input a multi-line commands
 * Return: Nothing
 */
void print_second_prompt(void)
{
	struct symtab_entry_s *entry = get_symtab_entry("PS2");

	if (entry && entry->val)
	{
		fprintf(stderr, "%s", entry->val);
	}
	else
	{
		fprintf(stderr, "> ");
	}
}
