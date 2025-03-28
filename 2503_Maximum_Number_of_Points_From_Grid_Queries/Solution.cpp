#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;

//[1,2,3]
//[2,5,7]
//[3,5,1]
//
// create root vector for union find
// flapping grid to 1D array
// mapping grid number to 1D array
// sorting queries
// iterate queries
// add grid number to map of set with grid number
// union find to merge the same number
// cnt the root[0] number
int find(vector<int> &root, int idx) {
	if (root[idx] == idx)
		return idx;
	return root[idx] = find(root, root[idx]);
}

vector<int> Solution::maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
	int m = grid.size();
	int n = grid[0].size();
	vector<int> root;
	vector<int> rootCnt(m * n, 1);
	map<int, vector<pair<int, int>>> valToRoot;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			valToRoot[grid[i][j]].emplace_back(pair<int, int>(i, j));
			root.emplace_back(i * n + j);
		}
	}

	vector<pair<int, int>> sortedQ(queries.size(), pair<int, int>());
	for (int i = 0; i < queries.size(); ++i) {
		sortedQ[i].first = queries[i];
		sortedQ[i].second = i;
	}
	sort(sortedQ.begin(), sortedQ.end());

	vector<int> result(queries.size(), 0);
	auto iter = valToRoot.begin();

	vector<int> dir = {1, 0, -1, 0, 1};

	for (const auto &[v, ri] : sortedQ) {
		if (v <= grid[0][0])
			continue;
		while (iter != valToRoot.end() && iter->first < v) {
			for (const auto &[x, y] : iter->second) {
				for (int di = 0; di < 4; ++di) {
					int nx = x + dir[di];
					int ny = y + dir[di + 1];
					if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] >= v)
						continue;

					int li = x * n + y;
					int ri = nx * n + ny;
					int lr = find(root, li);
					int rr = find(root, ri);
					if (lr == rr)
						continue;
					root[lr] = root[rr] = min(lr, rr);
					rootCnt[min(lr, rr)] += rootCnt[max(lr, rr)];
				}
			}
			++iter;
		}
		result[ri] = rootCnt[0];
	}
	return result;
}
