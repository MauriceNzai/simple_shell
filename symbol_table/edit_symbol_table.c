#include "symbol_table.h"

/**
 * add_to_symtab - Add a new entry to the local symbol table
 * @symbol: Pointer to the uniqyue key for entry to be added
 * Return:Pointer to the new entry added
 */
struct symtab_entry_s *add_to_symtab(char *symbol)
{
	if (!symbol || symbol[0] == '\0')
	{
		return (NULL);
	}

	struct symtab_s *st = symtab_stack.local_symtab;
	struct symtab_entry_s *entry = NULL;

	if ((entry = do_lookup(symbol, st)))
	{
		return (entry);
	}

	entry = malloc(sizeof(struct symtab_entry_s));

	if (!entry)
	{
		fprintf(stderr, "fetal error: no memory for new symbol table entry\n");
		exit(EXIT_FAILURE);
	}

	memset(entry, 0, sizeof(struct symtab_entry_s));
	entry->name = malloc(strlen(symbol) + 1);

	if (!entry->name)
	{
		fprintf(stderr, "fetal error: no memory for new symbol table entry\n");
		exit(EXIT_FAILURE);
	}

	strcpy(entry->name, symbol);

	if (!st->first)
	{
		st->first = entry;
		st->last = entry;
	}
	else
	{
		st->last->next = entry;
		st->last = entry;
	}

	return (entry);
}

/**
 * rem_from_symtab - Removes entry by freeing memory used for the entry
 * @entry: Pointer to symtab_entry_s structure
 * @symtab: Pointer to symtab_s structure
 * Return: 1 (continue)
 */
int rem_from_symtab(struct symtab_entry_s *entry, struct symtab_s *symtab)
{
	int res = 0;

	if (entry->val)
	{
		free(entry->val);
	}

	if (entry->func_body)
	{
		free_node_tree(entry->func_body);
	}

	free(entry->name);

	if (symtab->first == entry)
	{
		symtab->first = symtab->first->next;

		if (symtab->last == entry)
		{
			symtab->last = NULL;
		}
		res = 1;

	}

	else
	{
		struct symtab_entry_s *e = symtab->first;
		struct symtab_entry_s *p = NULL;

		while (e && e != entry)
		{
			p = e;
			e = e->next;
		}

		if (e == entry)
		{
			p->next = entry->next;
			res = 1;
		}
	}

	free(entry);
	return (res);
}

/**
 * do_lookup - Searches symbol table for given entry
 * @str: Pointer to the entry to be searched for
 * @symtable: Pointer to the symbol table to search for entry from
 * Return: NULL
 */
struct symtab_entry_s *do_lookup(char *str, struct symtab_s *symtable)
{
	if (!str || !symtable)
	{
		return (NULL);
	}

	struct symtab_entry_s *entry = symtable->first;

	while (entry)
	{
		if (strcmp(entry->name, str) == 0)
		{
			return (entry);
		}
		entry = entry->next;
	}

	return (NULL);

}

/**
 * get_symtab_entry - Searches the symbol table for a given entry
 * @str: Pointer to the unique key of entry to search for
 * Return: NULL
 */
struct symtab_entry_s *get_symtab_entry(char *str)
{
	int i = symtab_stack.symtab_count - 1;

	do {
		struct symtab_s *symtab = symtab_stack.symtab_list[i];
		struct symtab_entry_s *entry = do_lookup(str, symtab);

		if (entry)
		{
			return (entry);
		}

	} while (--i >= 0);

	return (NULL);
}

/**
 * symtab_entry_setval - Frees memory used to store entry values
 * @entry: Pointer to the entry to be freed
 * @val: pointer to the value of the entry to be freed
 * Return: Nothing
 */
void symtab_entry_setval(struct symtab_entry_s *entry, char *val)
{
	if (entry->val)
	{
		free(entry->val);
	}

	if (!val)
	{
		entry->val = NULL;
	}

	else
	{
		char *val2 = malloc(strlen(val) + 1);

		if (val2)
		{
			strcpy(val2, val);
		}

		else
		{
			fprintf(stderr, "error: no memory for symbol table entry's value\n");
		}

		entry->val = val2;
	}

}
