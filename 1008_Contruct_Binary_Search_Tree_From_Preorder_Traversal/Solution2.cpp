#include <Solution.h>
#include <iostream>

TreeNode* construct(vector<int>& preorder, int start, int end) {
	if (start >= end) return nullptr;

	TreeNode* node = new TreeNode(preorder[start]);
	int i = start + 1;
	for (; i < end ; ++i) {
		if (preorder[i] > preorder[start]) break;
	}
	node->left = construct(preorder, start + 1, i);
	node->right = construct(preorder, i, end);
	return node;
}

TreeNode* Solution::bstFromPreorder2(vector<int>& preorder) {
	return construct(preorder, 0, preorder.size());
}
