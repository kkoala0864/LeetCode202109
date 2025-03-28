#include <Solution.h>
#include <iostream>

using std::swap;
TreeNode *Solution::invertTree2(TreeNode *root) {
	if (!root)
		return root;
	swap(root->left, root->right);
	invertTree2(root->left);
	invertTree2(root->right);
	return root;
}
