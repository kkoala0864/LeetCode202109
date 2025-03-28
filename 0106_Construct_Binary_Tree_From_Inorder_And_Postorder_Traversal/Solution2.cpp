#include <Solution.h>
#include <iostream>

TreeNode *construct(const vector<int> &in, const vector<int> &post, int istart, int iend, int pstart, int pend) {
	if (pstart > pend)
		return nullptr;
	TreeNode *node = new TreeNode(post[pend]);

	if (pstart == pend)
		return node;

	int i = istart;
	while (i <= iend && in[i] != post[pend])
		++i;

	int size = i - istart;
	node->left = construct(in, post, istart, i - 1, pstart, pstart + size - 1);
	node->right = construct(in, post, i + 1, iend, pstart + size, pend - 1);
	return node;
}

TreeNode *Solution::buildTree2(vector<int> &inorder, vector<int> &postorder) {
	return construct(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
}
