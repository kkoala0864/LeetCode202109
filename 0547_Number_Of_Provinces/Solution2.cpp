#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int find2(vector<int> &group, int idx) {
	if (group[idx] == idx)
		return idx;
	return group[idx] = find2(group, group[idx]);
}

int Solution::findCircleNum2(vector<vector<int>> &isConnected) {
	int result = isConnected.size();
	vector<int> group;

	for (int i = 0; i < isConnected.size(); ++i)
		group.emplace_back(i);

	for (int i = 0; i < isConnected.size(); ++i) {
		for (int j = i + 1; j < isConnected.size(); ++j) {
			if (isConnected[i][j] == 1) {
				int l = find2(group, i);
				int r = find2(group, j);
				if (l != r) {
					--result;
					group[l] = group[r] = min(l, r);
				}
			}
		}
	}
	return result;
}
