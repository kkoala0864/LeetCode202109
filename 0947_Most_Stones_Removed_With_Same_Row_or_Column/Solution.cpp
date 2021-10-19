#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <climits>

using std::unordered_map;

void dfs(vector<vector<int>>& stones, unordered_map<int, vector<int>>& xMap, unordered_map<int, vector<int>>& yMap, vector<int>& cur, vector<int>& flag) {
	for (const auto& iter : xMap[cur[0]]) {
		if (flag[iter] == 0) {
			flag[iter] = 1;
			dfs(stones, xMap, yMap, stones[iter], flag);
		}
	}
	for (const auto& iter : yMap[cur[1]]) {
		if (flag[iter] == 0) {
			flag[iter] = 1;
			dfs(stones, xMap, yMap, stones[iter], flag);
		}
	}
}

int Solution::removeStones(vector<vector<int>>& stones) {
	int size = stones.size();
	unordered_map<int, vector<int>> xMap;
	unordered_map<int, vector<int>> yMap;
	vector<int> flag(stones.size(), 0);
	int cnt = 0;

	for (int i = 0 ; i < size ; ++i) {
		if (xMap.find(stones[i][0]) == xMap.end()) {
			xMap[stones[i][0]] = vector<int>();
		}

		xMap[stones[i][0]].emplace_back(i);
		if (yMap.find(stones[i][1]) == yMap.end()) {
			yMap[stones[i][1]] = vector<int>();
		}
		yMap[stones[i][1]].emplace_back(i);
	}

	for (int i = 0 ; i < size ; ++i) {
		if (flag[i] != 1 && flag[i] != 2) {
			++cnt;
			flag[i] = 2;
			dfs(stones, xMap, yMap, stones[i], flag);
		}
	}
	return stones.size() - cnt;
}
