#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

TreeNode *Solution::createBinaryTree(vector<vector<int>> &descriptions) {
	unordered_map<int, int> id;
	unordered_map<int, TreeNode *> tm;

	for (int i = 0; i < descriptions.size(); ++i) {
		TreeNode *cur = tm[descriptions[i][0]];
		if (!cur) {
			cur = new TreeNode(descriptions[i][0]);
			tm[descriptions[i][0]] = cur;
		}
		TreeNode *next = tm[descriptions[i][1]];
		if (!next) {
			next = new TreeNode(descriptions[i][1]);
			tm[descriptions[i][1]] = next;
		}
		++id[descriptions[i][1]];
		if (descriptions[i][2] == 0) {
			cur->right = next;
		} else {
			cur->left = next;
		}
	}

	for (const auto &node : tm) {
		if (id[node.first] == 0)
			return node.second;
	}
	return nullptr;
}
