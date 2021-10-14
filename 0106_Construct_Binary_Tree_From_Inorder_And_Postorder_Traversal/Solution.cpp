#include <Solution.h>
#include <iostream>

TreeNode* construct(const vector<int>& inorder, int iStart, int iEnd, const vector<int>& postorder, int pStart, int pEnd) {
	if (iStart > iEnd) return nullptr;
	TreeNode* result = new TreeNode(postorder[pEnd]);

	for (int i = iStart ; i <= iEnd ; ++i) {
		if (inorder[i] == postorder[pEnd]) {
			result->left = construct(inorder, iStart, i-1, postorder, pStart, pStart + i - iStart - 1);
			result->right = construct(inorder, i+1, iEnd, postorder, pEnd - iEnd + i, pEnd - 1);
		}
	}
	return result;
}

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
	return construct(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
