#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::unordered_map;
using std::unordered_set;

int Solution::robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
	vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	int result = 0;
	unordered_map<int, unordered_set<int>> obs;

	for (const auto &ob : obstacles) {
		obs[ob[0]].emplace(ob[1]);
	}

	int di = 0;
	int x = 0;
	int y = 0;

	for (const auto &c : commands) {
		if (c == -1) {
			di = (di + 1) % 4;
		} else if (c == -2) {
			di = (di + 3) % 4;
		} else if (c > 0) {
			for (int i = 0; i < c; ++i) {
				int nx = x + dir[di][0];
				int ny = y + dir[di][1];
				if (obs.count(nx) && obs[nx].count(ny))
					break;
				x = nx;
				y = ny;
			}
			result = max(result, x * x + y * y);
		}
	}
	return result;
}
