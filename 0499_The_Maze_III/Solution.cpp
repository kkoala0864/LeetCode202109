#include <Solution.h>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using std::queue;
using std::pair;
using std::min;

string Solution::findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
	queue<pair<vector<int>, string>> que;
	int m = maze.size();
	int n = maze[0].size();

	vector<vector<string>> ins(m, vector<string>(n, ""));
	vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
	que.emplace(pair<vector<int>, string>(vector<int>({ball[0], ball[1], 0}), ""));
	ins[ball[0]][ball[1]] = "";
	cost[ball[0]][ball[1]] = 0;
	string result = "";

	vector<int> dir = {1, 0, -1, 0, 1};
	string iss = "dlur";
	while (!que.empty()) {
		int x = que.front().first[0];
		int y = que.front().first[1];
		int ct = que.front().first[2];
		string is = que.front().second;
		que.pop();

		for (int i = 0 ; i < 4 ; ++i) {
			int nx = x;
			int ny = y;
			int tmpx = nx + dir[i];
			int tmpy = ny + dir[i+1];
			while (tmpx >= 0 && tmpy >= 0 && tmpx < m && tmpy < n && maze[tmpx][tmpy] != 1) {
				nx = tmpx;
				ny = tmpy;
				if (nx == hole[0] && ny == hole[1]) break;
				tmpx += dir[i];
				tmpy += dir[i+1];
			}
			if (nx != x || ny != y) {
				int diff = ct + abs(nx - x) + abs(ny - y);
				if (diff > cost[nx][ny]) continue;
				string tmp = is;
				tmp.push_back(iss[i]);
				if (diff < cost[nx][ny] || ins[nx][ny] > tmp) {
					cost[nx][ny] = diff;
					ins[nx][ny] = tmp;
					que.emplace(pair<vector<int>, string>(vector<int>({nx, ny, diff}), tmp));
				}
			}
		}
	}
	return cost[hole[0]][hole[1]] == INT_MAX ? "impossible" : ins[hole[0]][hole[1]];
}
