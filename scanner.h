#ifndef SCANNER_H
#define SCANNER_H

#define EOF                           (-1)
#define ERRCHAR                       (0)

#define INIT_SRC_POS                  (-2)

struct scanner_s
{
	char *buffer;                 /* the input text */
	long bufsize;                 /* size of the input text */
	long charpos;                 /* absolute char position in source */
};

char next_char(struct scanner_s *src);
void unget_char(struct scanner_s *src);
char peek_char(struct scanner_s *src);
void skip_white_spaces(struct scanner_s *src);

#endif
