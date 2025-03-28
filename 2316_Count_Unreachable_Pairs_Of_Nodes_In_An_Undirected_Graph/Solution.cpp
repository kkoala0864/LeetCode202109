#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::min;
using std::unordered_map;

int find(vector<int> &root, int val) {
	if (root[val] == val)
		return val;
	return root[val] = find(root, root[val]);
}

long long Solution::countPairs(int n, vector<vector<int>> &edges) {
	vector<int> root;
	for (int i = 0; i < n; ++i)
		root.emplace_back(i);

	for (const auto &e : edges) {
		int lr = find(root, e[0]);
		int rr = find(root, e[1]);

		if (lr == rr)
			continue;
		root[lr] = root[rr] = min(lr, rr);
	}

	unordered_map<int, long long> cnt;
	for (int i = 0; i < n; ++i) {
		++cnt[find(root, i)];
	}

	long long result = 0;
	long long remainCnt = n;
	for (const auto &e : cnt) {
		result += e.second * (remainCnt - e.second);
		remainCnt -= e.second;
	}

	return result;
}
