#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::queue;
using std::sort;
using std::vector;
using std::unordered_map;
using std::swap;

int help(vector<int>& list) {
	unordered_map<int, int> idx;

	for (int i = 0 ; i < list.size() ; ++i) {
		idx[list[i]] = i;
	}
	auto ori = list;
	sort(list.begin(), list.end());
	int ret = 0;
	for (int i = 0 ; i < list.size() ; ++i) {
		if (list[i] != ori[i]) {
			int curIdx = idx[list[i]];
			swap(idx[ori[i]], idx[list[i]]);
			swap(ori[i], ori[curIdx]);
			++ret;
		}
	}
	return ret;
}

int Solution::minimumOperations(TreeNode* root) {
	queue<TreeNode*> que, next;
	vector<int> list;

	que.emplace(root);
	int result = 0;

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		list.emplace_back(cur->val);

		if (cur->left) next.emplace(cur->left);
		if (cur->right) next.emplace(cur->right);

		if (que.empty()) {
			que = move(next);
			result += help(list);
			list.clear();
		}
	}
	return result;
}
