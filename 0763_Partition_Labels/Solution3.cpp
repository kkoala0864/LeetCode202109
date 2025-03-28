#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

vector<int> Solution::partitionLabels3(string s) {
	vector<int> maxLoc(26, -1);
	for (int i = 0; i < s.size(); ++i) {
		maxLoc[s[i] - 'a'] = i;
	}

	vector<int> result;
	int maxIdx = maxLoc[s[0] - 'a'];
	int start = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (i > maxIdx) {
			result.emplace_back(i - start);
			maxIdx = maxLoc[s[i] - 'a'];
			start = i;
		} else {
			maxIdx = max(maxIdx, maxLoc[s[i] - 'a']);
		}
	}
	result.emplace_back(s.size() - start);
	return result;
}
