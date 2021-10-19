#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using std::unordered_map;
using std::unordered_set;

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

void myUnion(int a, int b, vector<int>& parent) {
	while (parent[a] != a) a = parent[a];
	while (parent[b] != b) b = parent[b];
	parent[a] = b;
}

int Solution::removeStones(vector<vector<int>>& stones) {
	vector<int> parent;
	unordered_map<int, vector<int>> xMap;
	unordered_map<int, vector<int>> yMap;
	for (int i = 0 ; i < stones.size() ; ++i) {
		xMap[stones[i][0]].emplace_back(i);
		yMap[stones[i][1]].emplace_back(i);
	}

	for (int i = 0 ; i < stones.size() ; ++i) parent.emplace_back(i);

	for (int i = 0 ; i < stones.size() ; ++i) {
		for (const auto& x : xMap[stones[i][0]]) myUnion(i, x, parent);
		for (const auto& y : yMap[stones[i][1]]) myUnion(i, y, parent);
	}

	unordered_set<int> uSet;
	for (const auto& iter : parent) {
		int i = iter;
		while (i != parent[i]) i = parent[i];
		uSet.emplace(i);
	}
	return stones.size() - uSet.size();
}

