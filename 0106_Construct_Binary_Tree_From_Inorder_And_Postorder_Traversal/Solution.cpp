#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

TreeNode *construct(unordered_map<int, int> &uMap, const vector<int> &inorder, int iStart, int iEnd, const vector<int> &postorder, int pStart, int pEnd) {
	if (iStart > iEnd)
		return nullptr;
	TreeNode *result = new TreeNode(postorder[pEnd]);

	int i = uMap[postorder[pEnd]];
	result->left = construct(uMap, inorder, iStart, i - 1, postorder, pStart, pStart + i - iStart - 1);
	result->right = construct(uMap, inorder, i + 1, iEnd, postorder, pEnd - iEnd + i, pEnd - 1);
	return result;
}

TreeNode *Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
	unordered_map<int, int> uMap;
	for (int i = 0; i < inorder.size(); ++i)
		uMap[inorder[i]] = i;
	return construct(uMap, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}
