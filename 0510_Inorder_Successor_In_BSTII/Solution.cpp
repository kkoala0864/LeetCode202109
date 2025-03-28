#include <Solution.h>
#include <iostream>

Node *Solution::inorderSuccessor(Node *node) {
	Node *iter = node->right;
	while (iter && iter->left) {
		iter = iter->left;
	}
	if (iter)
		return iter;

	iter = node;
	while (iter && iter->parent && iter->parent->right == iter)
		iter = iter->parent;
	return iter ? iter->parent : iter;
}
