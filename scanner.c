#include "simple_shell.h"
/**
 * unget_char - unget last character retieved from input
 * @src: pointer to last input char
 * Return: nothing
 */
void unget_char(struct scanner_s *src)
{
	if (src->charpos < 0)
	{
		return;
	}
	src->charpos--;
}
/**
 * next_char - gets the ext char of input and updates pointers
 * @src: pointer to the next char of input
 * Return: returns following char of input or specialchar EOF
 */
char next_char(struct scanner_s *src)
{
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}
	char c1 = 0;

	if (src->charpos == INIT_SRC_POS)
	{
		src->charpos = -1;
	}
	else
	{
		c1 = src->buffer[src->charpos];
	}
	if (++src->charpos >= src->bufsize)
	{
		src->charpos = src->bufsize;
		return (EOF);
	}
	return (src->buffer[src->charpos]);
}
/**
 * peek_char - peeks the next input char
 * @src: pointer to the next input char
 * Return:the next input char
 */
char peek_char(struct scanner_s *src)
{
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}
	long pos = src->charpos;

	if (pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;
	if (pos >= src->bufsize)
	{
		return (EOF);
	}
	return (src->buffer[pos]);
}
/**
 * skip_white_spaces - skips white spaces input by user
 * @src: pointer to the next char
 * Return: nothing
 */
void skip_white_spaces(struct scanner_s *src)
{
	char c;

	if (!src || !src->buffer)
	{
		return;
	}
	while (((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
	{
		next_char(src);
	}
}
