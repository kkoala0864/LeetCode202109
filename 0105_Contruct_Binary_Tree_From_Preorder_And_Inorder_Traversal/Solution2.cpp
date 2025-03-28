#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

TreeNode *construct(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, unordered_map<int, int> &uMap) {
	if (preStart > preEnd)
		return nullptr;
	if (preStart == preEnd)
		return new TreeNode(pre[preStart]);

	int rootVal = pre[preStart];
	TreeNode *root = new TreeNode(rootVal);
	int i = uMap[rootVal];

	int leftSize = i - inStart;
	root->left = construct(pre, preStart + 1, preStart + leftSize, in, inStart, i - 1, uMap);
	root->right = construct(pre, preStart + leftSize + 1, preEnd, in, i + 1, inEnd, uMap);
	return root;
}

TreeNode *Solution::buildTree2(vector<int> &preorder, vector<int> &inorder) {
	unordered_map<int, int> uMap;
	for (int i = 0; i < inorder.size(); ++i)
		uMap[inorder[i]] = i;
	return construct(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, uMap);
}
