#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

int find(unordered_map<int, int>& root, int idx) {
	if (root.count(idx) == 0) {
		root[idx] = idx;
	}
	if (root[idx] == idx) return idx;
	return root[idx] = find(root, root[idx]);
}

int Solution::latestDayToCross(int row, int col, vector<vector<int>>& cells) {
	unordered_map<int, int> root;
	unordered_set<int> flood;
	unordered_map<int, unordered_set<int>> floody;

	vector<int> dir = {1, 0, -1, 0, 1, -1, -1, 1, 1};

	for (int i = 0 ; i < cells.size() ; ++i) {
		int idx = cells[i][0] * col + cells[i][1];
		floody[idx].emplace(cells[i][1]);

		for (int j = 0 ; j < 8 ; ++j) {
			int nx = cells[i][0] + dir[j];
			int ny = cells[i][1] + dir[j+1];
			if (nx < 1 || ny < 1 || nx > row || ny > col) continue;

			int nIdx = nx * col + ny;
			if (flood.count(nIdx) == 0) continue;

			int lr = find(root, idx);
			int rr = find(root, nIdx);
			if (lr == rr) continue;

			int minIdx = min(lr, rr);
			int maxIdx = max(lr, rr);
			root[lr] = root[rr] = minIdx;
			for (const auto& e : floody[maxIdx]) {
				floody[minIdx].emplace(e);
			}
			if (floody[minIdx].size() == col) return i;
		}
		flood.emplace(idx);
	}
	return 0;
}
