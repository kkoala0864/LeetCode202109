#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::min;
using std::unordered_map;
using std::unordered_set;

int find2(vector<int> &m, int idx) {
	if (m[idx] == idx)
		return idx;
	return m[idx] = find2(m, m[idx]);
}

int Solution::removeStones4(vector<vector<int>> &stones) {
	unordered_map<int, vector<int>> rows, cols;
	vector<int> roots;
	int result = 0;

	for (int i = 0; i < stones.size(); ++i) {
		roots.emplace_back(i);
		rows[stones[i][0]].emplace_back(i);
		cols[stones[i][1]].emplace_back(i);
	}

	for (const auto &e : rows) {
		auto r = e.second;
		for (int i = 0; i < r.size(); ++i) {
			for (int j = i + 1; j < r.size(); ++j) {
				int lr = find2(roots, r[i]);
				int rr = find2(roots, r[j]);
				if (lr == rr)
					continue;
				++result;
				roots[lr] = roots[rr] = min(lr, rr);
			}
		}
	}
	for (const auto &e : cols) {
		auto c = e.second;
		for (int i = 0; i < c.size(); ++i) {
			for (int j = i + 1; j < c.size(); ++j) {
				int lr = find2(roots, c[i]);
				int rr = find2(roots, c[j]);
				if (lr == rr)
					continue;
				++result;
				roots[lr] = roots[rr] = min(lr, rr);
			}
		}
	}
	return result;
}
