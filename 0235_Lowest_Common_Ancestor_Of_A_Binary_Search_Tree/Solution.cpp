#include <Solution.h>
#include <iostream>

using std::swap;

TreeNode *Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (p->val > q->val)
		swap(p, q);
	if (root->val == p->val || root->val == q->val)
		return root;
	if (root->val > p->val && root->val < q->val)
		return root;

	if (root->val > q->val)
		return lowestCommonAncestor(root->left, p, q);
	else
		return lowestCommonAncestor(root->right, p, q);
}
