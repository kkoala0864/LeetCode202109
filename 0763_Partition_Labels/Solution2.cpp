#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;

vector<int> Solution::partitionLabels2(string s) {
	vector<int> map(26, 0);
	for (int i = 0 ; i < s.size() ; ++i) {
		map[s[i]-'a'] = max(map[s[i]-'a'], i);
	}

	vector<int> result;
	int curMax = 0;
	int start = 0;
	for (int i = 0 ; i < s.size() ; ++i) {
		int idx = s[i] - 'a';
		curMax = max(map[idx], curMax);
		if (i == curMax) {
			result.emplace_back(i - start + 1);
			start = i + 1;
		}
	}

	return result;
}
