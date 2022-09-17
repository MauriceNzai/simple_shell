#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include "scanner.h"
#include "parser.h"
#include "executor.h"
#include "tokens.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "symbol_table/symbol_table.h"

void print_first_prompt(void);
void print_second_prompt(void);

char *read_command(void);
int parse_and_execute(struct scanner_s *src);
void init_shell(void);

/* shell builtin utilities */
int env(int argc, char **argv);

/**
 * struct builtin_s - structure for builtin utilities
 * @name: utility name
 * @func: function to execute the utility
 */
struct builtin_s
{
	char *name;	/* utility name */
	int (*func)(int argc,  char **argv); /* function call to excute utility */
};
/* the list of built utilities */
extern struct builtin_s builtins[];

/* and their count */
extern int builtins_count;

#endif
