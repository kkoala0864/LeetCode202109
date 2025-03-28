#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;

int diameter(TreeNode *root, int &MaxVal) {
	if (!root)
		return 0;
	int leftHeight = diameter(root->left, MaxVal);
	int rightHeight = diameter(root->right, MaxVal);
	MaxVal = max(MaxVal, leftHeight + rightHeight);
	return max(leftHeight, rightHeight) + 1;
}

int Solution::diameterOfBinaryTree(TreeNode *root) {
	int MaxVal = INT_MIN;
	diameter(root, MaxVal);
	return MaxVal;
}
