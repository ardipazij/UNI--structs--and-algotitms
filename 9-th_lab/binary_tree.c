#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>
void destroy(Tree_node ** head)
{
	if ((*head) == NULL)
		return;

	destroyTree((*head)->left);
	destroyTree((*head)->right);
	free(*head);
}