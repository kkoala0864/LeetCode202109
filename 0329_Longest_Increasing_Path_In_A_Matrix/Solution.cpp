#include <Solution.h>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <queue>

using std::map;
using std::pair;
using std::unordered_set;
using std::max;
using std::queue;
using std::cout;
using std::endl;

vector<pair<int, int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

int Solution::topologicalSort(vector<vector<int>>& matrix) {
	vector<vector<int>> outdegree(matrix.size(), vector<int>(matrix[0].size(), 0));
	queue<pair<int, int>> que, next;

	for (int i = 0 ; i < matrix.size() ; ++i) {
		for (int j = 0 ; j < matrix[0].size() ; ++j) {
			for (const auto& d : dir) {
				int nx = i + d.first;
				int ny = j + d.second;
				if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()) continue;
				if (matrix[i][j] < matrix[nx][ny]) ++outdegree[i][j];
			}
			if (outdegree[i][j] == 0) que.push({i, j});
		}
	}

	int result = 0;
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();
		for (const auto& d : dir) {
			int nx = cur.first + d.first;
			int ny = cur.second + d.second;
			if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()) continue;
			if (matrix[nx][ny] < matrix[cur.first][cur.second]) {
				if (--outdegree[nx][ny] == 0) next.push({nx, ny});
			}
		}

		if (que.empty()) {
			que = move(next);
			++result;
		}
	}
	return result == 0 ? 1 : result;
}


int Solution::longestIncreasingPath(vector<vector<int>>& matrix) {
	map<int, vector<pair<int, int>>> m;
	vector<vector<int>> len(matrix.size(), vector<int>(matrix[0].size(), 1));
	unordered_set<int> last;

	for (int i = 0 ; i < matrix.size() ; ++i) {
		for (int j = 0 ; j < matrix[0].size() ; ++j) {
			m[matrix[i][j]].push_back({i, j});
		}
	}

	int result = 1;
	for (auto& vec : m) {
		for (auto& loc : vec.second) {
			for (const auto& d : dir) {
				int nx = loc.first + d.first;
				int ny = loc.second + d.second;
				if (nx < 0 || ny < 0 || nx >= matrix.size() || ny >= matrix[0].size()) continue;
				if (last.find(nx^ny) != last.end() && matrix[nx][ny] < matrix[loc.first][loc.second]) {
					len[loc.first][loc.second] = max(len[nx][ny] + 1, len[loc.first][loc.second]);
				}
			}
			last.insert(loc.first ^ loc.second);
			result = max(len[loc.first][loc.second], result);
		}
	}
	return result;
}
