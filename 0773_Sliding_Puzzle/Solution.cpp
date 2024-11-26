#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>

using std::queue;
using std::swap;
using std::unordered_set;
using std::string;
using std::cout;
using std::endl;

string toString(vector<vector<int>>& v) {
	string result;
	for (const auto& i1 : v) {
		for (const auto& i2 : i1) result.push_back(i2 + '0');
	}
	return result;
}

int Solution::slidingPuzzle(vector<vector<int>>& board) {
	unordered_set<string> us;
	string golden = "123450";
	int m = board.size();
	int n = board[0].size();

	queue<vector<vector<int>>> que, next;
	int level = 0;
	que.emplace(board);
	us.emplace(toString(board));

	vector<int> dir = {1, 0, -1, 0, 1};

	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		if (toString(cur) == golden) return level;

		int x = 0;
		int y = 0;
		bool find = false;
		for (int i = 0 ; i < m ; ++i) {
			for (int j = 0 ; j < n ; ++j) {
				if (cur[i][j] == 0) {
					x = i;
					y = j;
					find = true;
					break;
				}
			}
			if (find) break;
		}

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x + dir[i];
			int ny = y + dir[i+1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

			auto tmp = cur;
			swap(tmp[nx][ny], tmp[x][y]);
			string nStr = toString(tmp);
			if (us.count(nStr)) continue;
			next.emplace(tmp);
			us.emplace(nStr);
		}

		if (que.empty()) {
			que = move(next);
			++level;
		}
	}
	return -1;
}
