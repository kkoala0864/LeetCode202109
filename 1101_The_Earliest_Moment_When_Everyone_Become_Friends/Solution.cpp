#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::sort;

int find(vector<int> &root, int val) {
	if (root[val] == val)
		return val;
	return root[val] = find(root, root[val]);
}

int Solution::earliestAcq(vector<vector<int>> &logs, int n) {
	vector<int> root;
	for (int i = 0; i < n; ++i)
		root.emplace_back(i);

	sort(logs.begin(), logs.end());
	for (const auto &l : logs) {
		int lr = find(root, l[1]);
		int rr = find(root, l[2]);
		if (lr == rr)
			continue;
		root[lr] = root[rr] = min(lr, rr);
		--n;
		if (n == 1)
			return l[0];
	}
	return -1;
}
