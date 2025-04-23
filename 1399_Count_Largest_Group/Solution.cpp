#include <Solution.h>
#include <iostream>
#include <map>
#include <vector>

int getCnt(string n, int rest, int idx, bool tight, vector<vector<vector<int>>>& cache) {
	if (rest < 0) return 0;
	if (idx == n.size()) return rest == 0;
	if (cache[idx][rest][tight] != -1) return cache[idx][rest][tight];

	cache[idx][rest][tight] = 0;
	int end = tight ? min(rest, n[idx] - '0') : min(rest, 9);
	for (int i = 0 ; i <= end ; ++i) {
		cache[idx][rest][tight] += getCnt(n, rest - i, idx + 1, tight && (i == n[idx] - '0'), cache);
	}
	return cache[idx][rest][tight];
}

int Solution::countLargestGroup(int n) {
	map<int, int> m;

	string ns = to_string(n);
	int maxValue = 9 * ns.size();
	vector<vector<vector<int>>> cache(ns.size() + 1, vector<vector<int>>(maxValue + 1, vector<int>(2, -1)));
	for (int i = 1 ; i <= maxValue ; ++i) {
		int ret = getCnt(ns, i, 0, true, cache);
		if (ret > 0) ++m[ret];
	}
	return m.rbegin()->second;
}
