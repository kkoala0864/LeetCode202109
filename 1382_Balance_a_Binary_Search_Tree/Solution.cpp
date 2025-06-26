#include <Solution.h>

void dfs(TreeNode* node, vector<TreeNode*>& list) {
	if (!node) return;
	dfs(node->left, list);
	list.emplace_back(node);
	dfs(node->right, list);
}

TreeNode* construct(int l, int r, vector<TreeNode*>& list) {
	if (l > r) return nullptr;
	if (l == r) {
		list[l]->left = nullptr;
		list[l]->right = nullptr;
		return list[l];
	}

	int mid = l + ((r - l) >> 1);
	list[mid]->left = construct(l, mid - 1, list);
	list[mid]->right = construct(mid + 1, r, list);
	return list[mid];
}

TreeNode* Solution::balanceBST(TreeNode* root) {
	vector<TreeNode*> list;
	dfs(root, list);

	return construct(0, list.size() - 1, list);
}
