#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int Solution::minimumRounds(vector<int> &tasks) {
	int result = 0;

	unordered_map<int, int> cnt;
	for (const auto &t : tasks)
		++cnt[t];

	for (auto &v : cnt) {
		if (v.second == 1)
			return -1;
		else if (v.second % 3 == 0)
			result += v.second / 3;
		else
			result += v.second / 3 + 1;
	}
	return result;
}
