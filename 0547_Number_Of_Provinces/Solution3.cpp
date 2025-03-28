#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using std::min;
using std::unordered_set;

int find3(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find3(root, root[idx]);
}

int Solution::findCircleNum3(vector<vector<int>> &isConnected) {
	vector<int> root;
	for (int i = 0; i < isConnected.size(); ++i)
		root.emplace_back(i);

	for (int i = 0; i < isConnected.size(); ++i) {
		for (int j = i + 1; j < isConnected.size(); ++j) {
			if (isConnected[i][j] == 0)
				continue;
			int r1 = find3(root, i);
			int r2 = find3(root, j);

			if (r1 == r2)
				continue;
			root[r1] = root[r2] = min(r1, r2);
		}
	}
	unordered_set<int> us;
	for (auto &v : root)
		us.emplace(find3(root, v));
	return us.size();
}
