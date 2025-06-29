#include <Solution.h>

void dfs(Node* node, unordered_map<char, int>& m) {
	if (!node) return;
	if (node->val != '+') {
		++m[node->val];
	}
	dfs(node->left, m);
	dfs(node->right, m);
}

bool Solution::checkEquivalence(Node* root1, Node* root2) {
	if (!root1 && !root2) return true;

	unordered_map<char, int> m1, m2;
	dfs(root1, m1);
	dfs(root2, m2);
	for (const auto& e : m1) {
		if (e.second != m2[e.first]) return false;
	}
	for (const auto& e : m2) {
		if (e.second != m1[e.first]) return false;
	}
	return true;
}
