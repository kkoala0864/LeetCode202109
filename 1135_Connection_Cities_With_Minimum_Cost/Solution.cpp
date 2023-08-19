#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <map>

using std::min;
using std::pair;
using std::map;
using std::cout;
using std::endl;

int find(int idx, vector<int>& root) {
	if (idx == root[idx]) return idx;
	return root[idx] = find(root[idx], root);
}

int Solution::minimumCost(int n, vector<vector<int>>& connections) {
	vector<int> root;
	for (int i = 0 ; i < n ; ++i) root.emplace_back(i);

	map<int, vector<pair<int, int>>> cost;
	for (const auto& c : connections) {
		cost[c[2]].emplace_back(pair<int, int>(c[0]-1, c[1]-1));
	}

	int result = 0;
	int cnt = n - 1;
	for (const auto& c : cost) {
		for (const auto& e : c.second) {
			int lr = find(e.first, root);
			int rr = find(e.second, root);
			if (lr == rr) continue;

			root[lr] = root[rr] = min(lr, rr);
			result += c.first;
			--cnt;
			if (cnt == 0) return result;
		}
	}
	return -1;
}
