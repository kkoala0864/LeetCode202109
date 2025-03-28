#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::min;
using std::swap;

int find(vector<int> &map, int val) {
	if (map[val] == val)
		return val;
	return map[val] = find(map, map[val]);
}

bool Solution::equationsPossible(vector<string> &equations) {
	vector<int> map;
	for (int i = 0; i < 26; ++i)
		map.emplace_back(i);

	for (const auto &e : equations) {
		if (e[1] == '!')
			continue;
		int lr = find(map, e[0] - 'a');
		int rr = find(map, e[3] - 'a');
		map[lr] = map[rr] = min(lr, rr);
	}

	for (const auto &e : equations) {
		if (e[1] == '=')
			continue;
		int lr = find(map, e[0] - 'a');
		int rr = find(map, e[3] - 'a');
		if (lr == rr)
			return false;
	}
	return true;
}
