#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using std::min;
using std::pair;
using std::unordered_set;
using std::cout;
using std::endl;

int find(vector<vector<int>>& m, int n, int x, int y) {
	if (m[x][y] == (x * n + y)) return (x * n + y);
	return m[x][y] = find(m, n, m[x][y] / n, m[x][y] % n);
}

vector<int> Solution::numIslands2(int m, int n, vector<vector<int>>& positions) {
	vector<int> result;
	vector<int> dir = {1, 0, -1, 0, 1};
	vector<vector<int>> map(m, vector<int>(n, -1));

	for (const auto& ps : positions) {
		if (map[ps[0]][ps[1]] != -1) {
			result.emplace_back(result.back());
			continue;
		}
		unordered_set<int> combine;
		int root = INT_MAX;
		for (int i = 0 ; i < 4 ; ++i) {
			int nx = ps[0] + dir[i];
			int ny = ps[1] + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n || map[nx][ny] == -1) continue;
			int lrt = find(map, n, nx, ny);
			root = min(lrt, root);
			combine.emplace(lrt);
		}
		map[ps[0]][ps[1]] = root == INT_MAX ? (ps[0] * n + ps[1]) : root;
		int curCnt = result.empty() ? 0 : result.back() - combine.size();
		for (const auto& val : combine) {
			if (val == root) continue;
			map[val / n][val % n] = root;
		}
		result.emplace_back(curCnt + 1);
	}
	return result;
}
