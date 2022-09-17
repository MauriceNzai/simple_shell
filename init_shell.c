#include "simple_shell.h"

extern char **environ;


/**
 * init_shell - Initializes symbol table stack and
 * scans environment list adding variables and values to table
 *
 * Return: Nothing
 */
void init_shell(void)
{
	init_symtab();

	struct symtab_entry_s *entry;
	char **p2 = environ;

	while (*p2)
	{
		char *eq = strchr(*p2, '=');

		if (eq)
		{
			int len = eq - (*p2);
			char name[len + 1];

			strncpy(name, *p2, len);
			name[len] = '\0';
			entry = add_to_symtab(name);

			if (entry)
			{
				symtab_entry_setval(entry, eq + 1);
				entry->flags |= FLAG_EXPORT;
			}
		}
		else
		{
			entry = add_to_symtab(*p2);
		}
		p2++;

	}

	entry = add_to_symtab("PS1");
	symtab_entry_setval(entry, "simple_shell $ ");


	entry = add_to_symtab("PS2");
	symtab_entry_setval(entry, "> ");

}
