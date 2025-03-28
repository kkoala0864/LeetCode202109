#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int find(vector<int> &root, int val) {
	if (root[val] == val)
		return val;
	return root[val] = find(root, root[val]);
}

vector<int> Solution::findRedundantConnection(vector<vector<int>> &edges) {
	vector<int> root;
	for (int i = 0; i < edges.size(); ++i) {
		root.emplace_back(i);
	}

	for (const auto &e : edges) {
		int lr = find(root, e[0] - 1);
		int rr = find(root, e[1] - 1);
		if (lr == rr) {
			return {e[0], e[1]};
		}
		root[lr] = root[rr] = min(lr, rr);
	}
	return {};
}
