#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::pair;
using std::sort;

int Solution::earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
	vector<pair<int, int>> times;

	for (int i = 0; i < plantTime.size(); ++i) {
		times.emplace_back(pair<int, int>(plantTime[i], growTime[i]));
	}

	auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
		return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second > rhs.second;
	};

	sort(times.begin(), times.end(), cmp);

	int result = 0;
	int curPlant = 0;
	for (const auto &t : times) {
		curPlant += t.first;
		result = max(result, curPlant + t.second);
	}
	return result;
}
