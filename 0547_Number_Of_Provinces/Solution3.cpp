#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int find3(vector<int>& root, int idx) {
	if (root[idx] == idx) return idx;
	return root[idx] = find3(root, root[idx]);
}

int Solution::findCircleNum3(vector<vector<int>>& isConnected) {
	int result = isConnected.size();
	vector<int> root;
	for (int i = 0 ; i < isConnected.size() ; ++i) root.emplace_back(i);

	for (int i = 0 ; i < isConnected.size() ; ++i) {
		for (int j = i + 1; j < isConnected[i].size() ; ++j) {
			if (isConnected[i][j] == 0) continue;
			int lr = find3(root, i);
			int rr = find3(root, j);
			if (lr == rr) continue;
			--result;
			root[lr] = root[rr] = min(lr, rr);
		}
	}
	return result;
}
