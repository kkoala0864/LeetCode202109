#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>

using std::map;
using std::min;
using std::pair;
using std::unordered_map;

int find(unordered_map<int, int> &root, int idx) {
	if (root.count(idx) == 0 || root[idx] == idx) {
		root[idx] = idx;
		return idx;
	}
	return root[idx] = find(root, root[idx]);
}

vector<int> Solution::findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
	vector<bool> secret(n, false);
	secret[0] = true;
	secret[firstPerson] = true;

	map<int, vector<pair<int, int>>> timeline;
	for (const auto &m : meetings) {
		timeline[m[2]].emplace_back(pair<int, int>(m[0], m[1]));
	}

	for (const auto &t : timeline) {
		unordered_map<int, int> root;
		for (const auto &p : t.second) {
			int lr = find(root, p.first);
			int rr = find(root, p.second);
			if (lr == rr)
				continue;
			int croot = min(lr, rr);
			root[lr] = root[rr] = croot;
			secret[croot] = secret[croot] | (secret[lr] | secret[rr]);
		}
		for (const auto &e : root) {
			secret[e.first] = secret[e.first] | secret[find(root, e.first)];
		}
	}

	vector<int> result;
	for (int i = 0; i < n; ++i) {
		if (secret[i]) {
			result.emplace_back(i);
		}
	}
	return result;
}
