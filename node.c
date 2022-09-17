#include "simple_shell.h"

/**
 * new_node - Creates a new node and set its type
 * @type: the type of node created
 *
 * Return: Pointer to the newly created node
 */
struct node_s *new_node(enum node_type_e type)
{
	struct node_s *node = malloc(sizeof(struct node_s));

	if (!node)
	{
		return (NULL);
	}

	memset(node, 0, sizeof(struct node_s));
	node->type = type;

	return (node);
}

/**
 * add_child_node - Adds new child node and
 * increment root's node children field
 * @parent: Pointer to the root node
 * @child: Pointer to the created child node
 *
 * Return: Nothing
 */
void add_child_node(struct node_s *parent, struct node_s *child)
{
	if (!parent || !child)
	{
		return;
	}

	if (!parent->first_child)
	{
		parent->first_child = child;
	}

	else
	{
		struct node_s *sibling = parent->first_child;

		while (sibling->next_sibling)
		{
			sibling = sibling->next_sibling;
		}

		sibling->next_sibling = child;
		child->prev_sibling = sibling;
	}

	parent->children++;
}

/**
 * set_node_val_str - Sets a node's value to a given string
 * @node: Pointer to the struct node_s structure
 * @val: Pointer to the string value
 *
 * Return: Nothing
 */
void set_node_val_str(struct node_s *node, char *val)
{
	node->val_type = VAL_STR;

	if (!val)
	{
		node->val.str = NULL;
	}

	else
	{
		char *val2 = malloc(strlen(val) + 1);

		if (!val2)
		{
			node->val.str = NULL;
		}

		else
		{
			strcpy(val2, val);
			node->val.str = val2;
		}
	}
}

/**
 * free_node_tree - Frees memory used by a struct node_s structure
 * @node: Pointer to the freed struct node_s structure
 *
 * Return: Nothing
 */
void free_node_tree(struct node_s *node)
{
	if (!node)
	{
		return;
	}

	struct node_s *child = node->first_child;

	while (child)
	{
		struct node_s *next = child->next_sibling;

		free_node_tree(child);
		child = next;
	}

	if (node->val_type == VAL_STR)
	{
		if (node->val.str)
		{
			free(node->val.str);
		}
	}

	free(node);
}
