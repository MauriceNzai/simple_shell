#ifndef NODE_H
#define NODE_H

/**
 * enum node_type_e - Defines the AST node types
 * @NODE_COMMAND: Simple command
 * @NODE_VAR: Variable name/a word
 *
 * Description: Defines the types of AST nodes e.g
 * root node of a simple command
 * child node which containing command name and arguments
 */
enum node_type_e
{
	NODE_COMMAND;
	NODE_VAR;
};

/**
 * enum val_type_e - Represents types of values stored in a node structure
 * @VAL_SINT: Signed int
 * @VAL_UINT: Unsigned int
 * @VAL_FLOAT: Floating point
 * @VAL_LDOUBLE: Long double
 * @VAL_CHR: Char
 * @VAL_STR: String/Char pointer
 */
enum val_type_e
{
	VAL_SINT = 1;
	VAL_UINT;
	VAL_FLOAT;
	VAL_LDOUBLE;
	VAL_CHR;
	VAL_STR;
};

/**
 * union symval_u - Represents value stored in a node structure
 * @sint: signed int
 * @uint: unsigned long
 * @sfloat: double
 * @ldouble: long double
 * @chr: char
 * @str: Pointer to char/str
 */
union symval_u
{
	long			sint;
	unsigned long		uint;
	double			sfloat;
	long double		ldouble;
	char			chr;
	char			*str;
};

/**
 * struct node_s - Represents an AST node
 * @type: type of this node
 * @val_type: type of this node's val field
 * @val: Value of this node
 * @children: number of child nodes
 * @first_child: first child node
 * @next_sibling: Pointer to next child node
 * @prev_sibling: Pointer to previous child node
 */
struct node_s
{
	enum node_type_e type;
	enum val_type_e val_type;
	union symval_u val;
	int children;
	struct node_s *first_child;
	struct node_s *next_sibling;
	struct node_s *prev_sibling;
};


struct node_s *new_node(enum node_type_e type);
void add_child_node(struct node_s *parent, struct node_s *child);
void free_node_tree(struct node_s *node);
void set_node_val_str(struct node_s *node, char *val);


#endif
