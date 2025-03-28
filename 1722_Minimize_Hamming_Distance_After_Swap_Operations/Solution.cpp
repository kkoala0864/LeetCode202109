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

int Solution::minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
	vector<int> root;
	int size = source.size();
	for (int i = 0; i < size; ++i)
		root.emplace_back(i);

	for (const auto &a : allowedSwaps) {
		int lr = find(root, a[0]);
		int rr = find(root, a[1]);
		if (lr == rr)
			continue;
		root[lr] = root[rr] = min(lr, rr);
	}
	unordered_map<int, unordered_map<int, int>> mt;
	for (int i = 0; i < size; ++i) {
		++mt[target[i]][find(root, i)];
	}
	int cnt = 0;
	for (int i = 0; i < size; ++i) {
		int r = find(root, i);
		if (mt.count(source[i]) && mt[source[i]][r] > 0) {
			++cnt;
			--mt[source[i]][r];
		}
	}
	return size - cnt;
}
