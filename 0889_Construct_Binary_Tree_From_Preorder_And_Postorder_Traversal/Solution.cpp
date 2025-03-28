#include <Solution.h>
#include <iostream>

TreeNode *construct(vector<int> &preorder, int &preIdx, vector<int> &postorder, int postStart, int postEnd) {
	if (postStart == postEnd)
		return new TreeNode(postorder[postStart]);

	TreeNode *root = new TreeNode(preorder[preIdx++]);
	if (preIdx >= preorder.size())
		return nullptr;
	int leftVal = preorder[preIdx];
	int idx = postEnd;
	while (postorder[idx] != leftVal)
		--idx;

	root->left = construct(preorder, preIdx, postorder, postStart, idx);
	if ((idx + 1) <= (postEnd - 1)) {
		root->right = construct(preorder, ++preIdx, postorder, idx + 1, postEnd - 1);
	}
	return root;
}

TreeNode *constructRecur(vector<int> &pre, int &preIdx, vector<int> &post, int &postIdx) {
	TreeNode *root = new TreeNode(pre[preIdx++]);
	if (root->val != post[postIdx]) {
		root->left = constructRecur(pre, preIdx, post, postIdx);
	}
	if (root->val != post[postIdx]) {
		root->right = constructRecur(pre, preIdx, post, postIdx);
	}
	++postIdx;
	return root;
}

TreeNode *Solution::constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
	int preIdx = 0;
	int postIdx = 0;
	return constructRecur(preorder, preIdx, postorder, postIdx);
}
