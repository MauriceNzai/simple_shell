#include "simple_shell.h"
/**
 * _getline - prints the prompt "$ ", for user to input command
 * @input: pointer to buffer to store input
 * @size: size of a buffer
 * Return: chars read or -1 if _realloc failed
 */
int _getline(char *input, int size)
{
	int i;
	int readval;
	struct stat st;

	if (fstat(STDIN_FILENO, &st) == -1)
	{
		perror("fstat");
		exit(-1);
	}
	if ((st.st_mode & S_IFMT) != S_IFIFO)
		_strprint(PROMPT);
	for (i = 0; i < size - 1; i++)
	{
		readval = read(STDIN_FILENO, (input + i), 1);
		if (readval == 0)
			return (-1); /* EOF  */
		if (input[i] == '\n')
			break;
	}
	input[i] = '\0';
	return (i);
}

/**
 * exit_shell - 'exit' exits shell
 * @line_tok: pointer to a tokenized user input
 * Return: 1 if want to exit, 0 otherwise
 */
int exit_shell(char **line_tok)
{
	int cmp, lend, lline, size;

	size = arr_size(line_tok) < 3;
	cmp = _strncmp(line_tok[0], END, _strlen(END));
	lend = _strlen(END);
	lline = _strlen(line_tok[0]);
	if (cmp == 0 && lend == lline && size)
		return (1);
	return (0);
}

/**
 * clear_buffer - Resets buffer (sets all the chars in buffer to 0)
 * @buffer: buffer to reset
 * Return: nothing
 */
void clear_buffer(char *buffer)
{
	int i;

	for (i = 0; i < BUFF_SIZE; i++)
		buffer[i] = 0;
}

/**
 * mem_cpy - copies the memory area
 * @dest: memory area to copy to
 * @src: memory area copying from
 * @n: The number of bytes to copy
 * Return: Pointer to dest
 */
char *mem_cpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n - 1; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}
