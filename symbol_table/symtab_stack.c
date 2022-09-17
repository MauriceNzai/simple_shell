#include "symbol_table.h"

/**
 * symtab_stack_add - adds symbo table and assigns it as local table
 * @symtab: the symboltable to be aded
 * Return: nothing
 */
void symtab_stack_add(struct symtab_s *symtab)
{
	symtab_stack.symtab_list[symtab_stack.symtab_count++] = symtab;
	symtab_stack.local_symtab = symtab;
}

/**
 * symtab_stack_push - creates new emptysymbol table and pushes it to the tmp
 * Return: pointer to the creted stack
 */
struct symtab_s *symtab_stack_push(void)
{
	struct symtab_s *st = new_symtab(++symtab_level);

	symtab_stack_add(st);
	return (st);
}

/**
 * symtab_stack_pop - removes/pops symbol table from top of stack
 * Return: pointer to removed symbol table
 */
struct symtab_s *symtab_stack_pop(void)
{
	if (symtab_stack.symtab_count == 0)
	{
		return (NULL);
	}
	struct symtab_s *st = symtab_stack.symtab_list[symtab_count - 1];

	symtab_stack.symtab_list[--symtab_stack.symtab_count] = NULL;
	symtab_level--;

	if (symtab_stack.symtab_count == 0)
	{
		symtab_stack.local_symtab = NULL;
		symtab_stack.global_symtab = NULL;
	}
	else
	{
symtab_stack.local_symtab = symtab_stack.symtab_list[symtab_stack.symtab_count - 1];
	}
	return (st);
}
/**
 * get_local_symtab - Returns pointer to local symbol table
 * Return: Pointer to local symbol table
 */
struct symtab_s *get_local_symtab(void)
{
	return (symtab_stack.local_symtab);
}
/**
 * get_symtab_stack - Return pointer to symbol table stack
 * Return: pointer to symbol table stack
 */
struct symtab_stack_s *get_symtab_stack(void)
{
	return (&symtab_stack);
}
