#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using std::cout;
using std::endl;
using std::min;
using std::unordered_map;
using std::unordered_set;

int find2(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find2(root, root[idx]);
}

vector<int> Solution::numIslands22(int m, int n, vector<vector<int>> &positions) {
	vector<int> root;
	vector<int> dir = {1, 0, -1, 0, 1};
	vector<int> result;
	int cnt = 0;
	unordered_map<int, int> hashToIdx;

	for (int i = 0; i < positions.size(); ++i) {
		root.emplace_back(i);
		int curHash = positions[i][0] * n + positions[i][1];
		if (hashToIdx.count(curHash)) {
			result.emplace_back(result.back());
			root[i] = hashToIdx[curHash];
			continue;
		}
		hashToIdx[curHash] = i;
		++cnt;

		for (int d = 0; d < 4; ++d) {
			int nx = positions[i][0] + dir[d];
			int ny = positions[i][1] + dir[d + 1];
			int hash = nx * n + ny;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || hashToIdx.count(hash) == 0)
				continue;
			int lr = find2(root, hashToIdx[hash]);
			int rr = find2(root, i);
			if (lr == rr)
				continue;
			root[lr] = root[rr] = min(lr, rr);
			--cnt;
		}
		result.emplace_back(cnt);
	}
	return result;
}
