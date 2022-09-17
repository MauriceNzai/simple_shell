#include "simple_shell.h"


/**
 * env - Prints the environment variables
 * @argc: Number of arguments
 * @argv: Pointer to the array of arguments
 *
 * Return: 0 (Success)
 */
int env(int argc, char **argv)
{
	dump_local_symtab();
	return (0);
}

/**
 * exit - Exits the simple_shell
 * @argc: Number of arguments
 * @argv: Pointer to array of arguments
 *
 * Return: 0 (Success)
 */
/* void exit(int argc, char **argv) */
