#include <Solution.h>
#include <iostream>
#include <cmath>

int Solution::countNodes2(TreeNode *root) {
	return root ? 1 + countNodes2(root->left) + countNodes2(root->right) : 0;
}
