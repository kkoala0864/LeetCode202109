#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using std::min;
using std::unordered_set;

int find(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find(root, root[idx]);
}

bool check(const vector<int> &lhs, const vector<int> &rhs, int k) {
	int cnt = 0;
	for (int i = 1; i <= 100; ++i) {
		if (rhs[i] == 0)
			continue;
		if (lhs[i] > 0)
			++cnt;
		if (cnt >= k)
			return true;
	}
	return false;
}

int Solution::numberOfComponents(vector<vector<int>> &properties, int k) {
	int n = properties.size();
	vector<int> root;
	for (int i = 0; i < n; ++i) {
		root.emplace_back(i);
	}
	vector<vector<int>> valCnt(n, vector<int>(101, 0));
	for (int i = 0; i < n; ++i) {
		for (const auto &v : properties[i]) {
			++valCnt[i][v];
		}
		for (int j = 0; j < i; ++j) {
			int lr = find(root, i);
			int rr = find(root, j);
			if (lr == rr)
				continue;

			if (!check(valCnt[i], valCnt[j], k))
				continue;
			root[lr] = root[rr] = min(lr, rr);
		}
	}
	unordered_set<int> us;
	for (const auto &v : root)
		us.emplace(find(root, v));
	return us.size();
}
