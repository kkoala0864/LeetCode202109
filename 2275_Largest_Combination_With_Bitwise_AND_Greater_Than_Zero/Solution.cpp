#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

int Solution::largestCombination(vector<int>& candidates) {
	int result = 0;

	for (int i = 0 ; i < 32 ; ++i) {
		int mask = 1 << i;
		int cnt = 0;
		for (const auto& c : candidates) {
			if (c & mask) ++cnt;
		}
		result = max(result, cnt);
	}
	return result;
}
