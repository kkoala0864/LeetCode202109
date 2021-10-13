#include <Solution.h>
#include <iostream>

TreeNode* construct(const vector<int>& preorder, int start, int end) {
	if (start > end) return nullptr;
	if (start == end) return new TreeNode(preorder[start]);

	int root = preorder[start];
	int i = start + 1;
	for (; i <= end ; ++i) {
		if (preorder[i] > root) break;
	}

	TreeNode* cur = new TreeNode(root);
	cur->left = construct(preorder, start + 1, i - 1);
	cur->right = construct(preorder, i, end);
	return cur;
}

TreeNode* Solution::bstFromPreorder(vector<int>& preorder) {
	return construct(preorder, 0, preorder.size() - 1);
}
