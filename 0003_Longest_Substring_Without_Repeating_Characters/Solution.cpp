#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using std::max;
using std::vector;

int Solution::lengthOfLongestSubstring(string s) {
	if (s.empty())
		return 0;

	vector<int> record(256, -1);

	int max_size = INT_MIN;
	int start = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (-1 != record[s[i]]) {
			max_size = max(max_size, i - start);
			for (int j = start; j < record[s[i]]; ++j) {
				record[s[j]] = -1;
			}
			start = record[s[i]] + 1;
		}
		record[s[i]] = i;
	}
	max_size = max(max_size, (int)(s.size() - start));
	return max_size;
}
