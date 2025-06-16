#include <Solution.h>

void inorder(TreeNode* node, vector<int>& list) {
	if (!node) return;
	inorder(node->left, list);
	list.emplace_back(node->val);
	inorder(node->right, list);
}

vector<vector<int>> Solution::closestNodes(TreeNode* root, vector<int>& queries) {
	vector<int> list;
	inorder(root, list);

	vector<vector<int>> result;
	for (int i = 0 ; i < queries.size() ; ++i) {
		int idx = lower_bound(list.begin(), list.end(), queries[i]) - list.begin();
		if (idx == list.size()) {
			result.emplace_back(vector<int>({list[idx-1], -1}));
		} else {
			if (list[idx] == queries[i]) {
				result.emplace_back(vector<int>({list[idx], list[idx]}));
			} else if (idx == 0) {
				result.emplace_back(vector<int>({-1, list[idx]}));
			} else {
				result.emplace_back(vector<int>({list[idx-1], list[idx]}));
			}
		}
	}
	return result;
}
