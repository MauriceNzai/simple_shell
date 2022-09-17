#ifndef TOKENS_H
#define TOKENS_H

/**
 * struct token_s - Contains a pointer to struct scanner_s
 * @struct scanner_s: source of input
 * @text_len: Length of token text
 * @text: Pointer to token text
 * @src: pointer to the input
 *
 * Description: Contains a pointer to the
 * struct scanner_s that holds user input
 */
struct token_s
{
	struct scanner_s *src;
	int text_len;
	char *text;
};


/* the special EOF toke, which indicates the end of input */
extern struct token_s eof_token;

struct token_s *tokenize(struct scanner_s *src);
void free_token(struct token_s *tok);


#endif

