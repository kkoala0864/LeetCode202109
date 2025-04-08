#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int find(vector<int> &root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

int Solution::countComponents(int n, vector<vector<int>> &edges) {
	vector<int> root;
	for (int i = 0; i < n; ++i) root.emplace_back(i);
	for (const auto &e : edges) {
		int lr = find(root, e[0]);
		int rr = find(root, e[1]);
		if (lr == rr) continue;
		--n;
		root[lr] = root[rr] = min(lr, rr);
	}
	return n;
}
