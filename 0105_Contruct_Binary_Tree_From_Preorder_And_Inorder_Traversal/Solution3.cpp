#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

TreeNode *contruct(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &idx) {
	if (ps > pe)
		return nullptr;

	TreeNode *cur = new TreeNode(preorder[ps]);

	if (ps == pe)
		return cur;
	int curIdx = idx[cur->val];
	int leftChildSize = curIdx - is;

	cur->left = contruct(preorder, ps + 1, ps + leftChildSize, inorder, is, curIdx - 1, idx);
	cur->right = contruct(preorder, ps + leftChildSize + 1, pe, inorder, curIdx + 1, ie, idx);
	return cur;
}

TreeNode *Solution::buildTree3(vector<int> &preorder, vector<int> &inorder) {
	unordered_map<int, int> idx;
	int n = preorder.size();

	for (int i = 0; i < inorder.size(); ++i)
		idx[inorder[i]] = i;

	return contruct(preorder, 0, n - 1, inorder, 0, n - 1, idx);
}
