#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;

int find(vector<int>& root, int idx) {
	if (idx == root[idx]) return idx;
	return root[idx] = find(root, root[idx]);
}

vector<int> Solution::numIslands2(int m, int n, vector<vector<int>>& positions) {
	vector<int> root(m * n, INT_MAX);

	vector<int> result;
	vector<int> dir = {1, 0, -1, 0, 1};
	int cnt = 0;

	for (const auto& p : positions) {
		int x = p[0];
		int y = p[1];
		int val = x * n + y;
		if (root[val] != INT_MAX) continue;
		root[val] = val;
		++cnt;

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			int nVal = nx * n + ny;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || root[nVal] == INT_MAX) continue;
			int lr = find(root, val);
			int rr = find(root, nVal);

			if (lr == rr) continue;
			root[lr] = root[rr] = min(lr, rr);
			--cnt;
		}
		result.emplace_back(cnt);
	}
	return result;
}
