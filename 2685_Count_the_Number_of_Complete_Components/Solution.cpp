#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::min;
using std::unordered_map;

int find(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find(root, root[idx]);
}

int Solution::countCompleteComponents(int n, vector<vector<int>> &edges) {
	vector<int> root;
	for (int i = 0; i < n; ++i) {
		root.emplace_back(i);
	}
	vector<int> edgeCnt(n, 0);

	for (const auto &e : edges) {
		int lr = find(root, e[0]);
		int rr = find(root, e[1]);
		++edgeCnt[e[0]];
		++edgeCnt[e[1]];
		if (lr == rr)
			continue;
		root[lr] = root[rr] = min(lr, rr);
	}

	unordered_map<int, vector<int>> g;
	for (int i = 0; i < n; ++i) {
		g[find(root, i)].emplace_back(i);
	}

	int result = 0;
	for (const auto &e : g) {
		int sz = e.second.size();
		int i = 0;
		for (; i < sz; ++i) {
			if (edgeCnt[e.second[i]] != (sz - 1))
				break;
		}
		if (i == sz)
			++result;
	}
	return result;
}
