#include <Solution.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using std::max;
using std::unordered_map;

int Solution::maxFrequencyElements(vector<int>& nums) {
	vector<int> cnt(101, 0);
	for (const auto& v : nums) ++cnt[v];

	vector<int> freq(101, 0);
	for (const auto& c : cnt) {
		if (c == 0) continue;
		++freq[c];
	}
	for (int i = 100 ; i >= 1 ; --i) {
		if (freq[i] == 0) continue;
		return freq[i] * i;
	}
	return 0;
}
