#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "../simple_shell.h"
#define MAX_SYMTAB		256

/* global variable */
extern struct symtab_stack_s symtab_stack;
extern int symtab_level;

/**
 * enum symbol_type_e - define the type of a symbol table entry's value
 * @SYM_STR: represents shell variable
 * @SYM_FUNC: represents functions
 */
enum symbol_type_e
{
	SYM_STR,
	SYM_FUNC
};
/**
 * struct symtab_entry_s - represets the symbol table entrystructure
 * @name: name of the entry
 * @val_type: type of the entry
 * @val: the value of the entry
 * @flags: proerties assigned to variables
 * @next: pointer to the next symbol table entry
 * @func_body: AST of the function body
 */
struct symtab_entry_s
{
	char		*name;
	enum		symbol_type_e val_type;
	char		*val;
	unsigned int	flags;
	struct		symtab_entry_s *next;
	struct		node_s *func_body;
};
/**
 * struct symtab_s - reps the symbol table structure
 * @level: the level of the symbol table
 * @first: pointer of the first entry
 * @last: pointer to the last entry
 */
struct symtab_s
{
	int	level;
	struct	symtab_entry_s *first, *last;
};

/* values for the flags field of struct symtab_entry_s */
#define FLAG_EXPORT (1 << 0) /* export entry to forked commands */

/**
 * struct symtab_stack_s - structure representing the symbol table stack
 * @symtab_count: the number of symbols currently on the stack
 * @symtab_list: an array of pointers to the stack's symbol tables
 * @global_symtab: pointer to the global symbol table
 * @local_symtab: pointer to the local symbol table
 */
struct symtab_stack_s
{
	int symtab_count;
	struct symtab_s *symtab_list[MAX_SYMTAB];
	struct symtab_s *global_symtab, *local_symtab;
};

/* the function prototypes */
struct symtab_s *new_symtab(int level);
struct symtab_s *symab_stack_push(void);
struct symtab_s *symtab_stack_pop(void);
int rem_from_symtab(struct symtab_entry_s *entry, struct symtab_s *symtab);
struct symtab_entry_s *add_to_symtab(char *symbol);
struct symtab_entry_s *do_lookup(char *str, struct symtab_s *symtable);
struct symtab_entry_s *get_symtab_entry(char *str);
struct symtab_s *get_local_symtab(void);
struct symtab_s *get_global_symtab(void);
struct symtab_stack_s *get_symtab_stack(void);
void init_symtab(void);
void dump_local_symtab(void);
void free_symtab(struct symtab_s *symtab);
void symtab_entry_setval(struct symtab_entry_s *entry, char *val);
void symtab_stack_add(struct symtab_s *symtab);

#endif
