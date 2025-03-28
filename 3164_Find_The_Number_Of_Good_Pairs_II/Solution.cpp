#include <Solution.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <climits>

using std::map;
using std::max;

long long Solution::numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k) {
	map<int, long long> m;

	int maxValue = INT_MIN;
	for (const auto &v : nums1) {
		++m[v];
		maxValue = max(maxValue, v);
	}

	long long result = 0;
	for (const auto &v : nums2) {
		int n2 = v * k;

		int value = m.lower_bound(n2)->first;

		int idx = value / n2;
		while ((n2 * idx) <= maxValue) {
			int tmp = n2 * idx;
			if (m.count(tmp)) {
				result += m[tmp];
			}
			++idx;
		}
	}
	return result;
}
