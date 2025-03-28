#include <Solution.h>
#include <iostream>
#include <algorithm>
using std::max;

int Solution::garbageCollection(vector<string> &garbage, vector<int> &travel) {
	vector<int> t(3, 0);
	vector<int> preSum(1, 0);
	int sum = 0;
	int result = 0;

	for (int i = 0; i < garbage.size(); ++i) {
		if (i < garbage.size() - 1) {
			sum += travel[i];
			preSum.emplace_back(sum);
		}
		for (const auto &c : garbage[i]) {
			if (c == 'M') {
				t[0] = max(t[0], i);
			} else if (c == 'P') {
				t[1] = max(t[1], i);
			} else {
				t[2] = max(t[2], i);
			}
		}
		result += garbage[i].size();
	}
	for (int i = 0; i < 3; ++i) {
		result += preSum[t[i]];
	}

	return result;
}
