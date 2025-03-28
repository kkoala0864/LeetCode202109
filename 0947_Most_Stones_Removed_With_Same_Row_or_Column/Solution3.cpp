#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::min;
using std::unordered_map;

int find(vector<int> &root, int val) {
	if (root[val] == val)
		return val;
	return root[val] = find(root, root[val]);
}

int Solution::removeStones3(vector<vector<int>> &stones) {
	unordered_map<int, vector<int>> rows, cols;
	vector<int> root;
	int result = 0;

	for (int i = 0; i < stones.size(); ++i) {
		rows[stones[i][0]].emplace_back(i);
		cols[stones[i][1]].emplace_back(i);
		root.emplace_back(i);
	}

	for (const auto &r : rows) {
		for (int i = 0; i < r.second.size(); ++i) {
			for (int j = i + 1; j < r.second.size(); ++j) {
				int lr = find(root, r.second[i]);
				int rr = find(root, r.second[j]);
				if (lr == rr)
					continue;
				++result;
				root[lr] = root[rr] = min(lr, rr);
			}
		}
	}
	for (const auto &c : cols) {
		for (int i = 0; i < c.second.size(); ++i) {
			for (int j = i + 1; j < c.second.size(); ++j) {
				int lr = find(root, c.second[i]);
				int rr = find(root, c.second[j]);
				if (lr == rr)
					continue;
				++result;
				root[lr] = root[rr] = min(lr, rr);
			}
		}
	}
	return result;
}
