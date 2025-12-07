#include <Solution.h>

bool search(TreeNode* node, int target) {
	if (!node) return false;
	if (node->val == target) return true;
	if (target > node->val) {
		return search(node->right, target);
	} else {
		return search(node->left, target);
	}
}

bool Solution::twoSumBSTs(TreeNode *root1, TreeNode *root2, int target) {
	if (!root1) return false;
	int rest = target - root1->val;
	if (search(root2, rest)) return true;

	return twoSumBSTs(root1->left, root2, target) || twoSumBSTs(root1->right, root2, target);
}
