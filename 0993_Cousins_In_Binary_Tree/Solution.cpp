#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void find(TreeNode* root, int target, int& tdepth, int& parent, int depth, int parentVal) {
	if (!root) return;
	if (root->val == target) {
		tdepth = depth;
		parent = parentVal;
		return;
	}
	find(root->left, target, tdepth, parent, depth+1, root->val);
	find(root->right, target, tdepth, parent, depth+1, root->val);
}

bool Solution::isCousins(TreeNode* root, int x, int y) {
	int xDepth = 0;
	int xParent = 0;
	int yDepth = 0;
	int yParent = 0;

	find(root, x, xDepth, xParent, 0, 0);
	find(root, y, yDepth, yParent, 0, 0);
	if ((xDepth == yDepth) && (xParent != yParent)) return true;
	else return false;
}
