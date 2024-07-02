#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::min;

int find(vector<int>& root, int v) {
	if (root[v] == v) return v;
	return root[v] = find(root, root[v]);
}

void check(vector<int>& r, vector<pair<int, int>>& edge, int& result) {
	for (const auto& e : edge) {
		int lr = find(r, e.first);
		int rr = find(r, e.second);
		if (lr == rr) ++result;
		else r[lr] = r[rr] = min(lr, rr);
	}
}

int Solution::maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
	vector<int> r1, r2;
	for (int i = 0 ; i < n ; ++i) r1.emplace_back(i);

	int result = 0;
	vector<pair<int, int>> e1, e2;
	for (const auto& e : edges) {
		if (e[0] == 1) {
			e1.emplace_back(pair<int, int>(e[1]-1, e[2]-1));
		} else if (e[0] == 2) {
			e2.emplace_back(pair<int, int>(e[1]-1, e[2]-1));
		} else {
			int lr = find(r1, e[1]-1);
			int rr = find(r1, e[2]-1);
			if (lr == rr) ++result;
			else r1[lr] = r1[rr] = min(lr, rr);
		}
	}

	r2 = r1;
	check(r1, e1, result);
	check(r2, e2, result);
	for (int i = 0 ; i < n ; ++i) {
		if (find(r1, i) != 0) return -1;
		if (find(r2, i) != 0) return -1;
	}
	return result;
}
