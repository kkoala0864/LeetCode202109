#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::cout;
using std::endl;
using std::max;

vector<int> Solution::partitionLabels(string s) {
	vector<int> result;
	vector<int> maxIdx(26, -1);
	for (int i = 0; i < s.size(); ++i)
		maxIdx[s[i] - 'a'] = i;

	int l = 0;
	int curMax = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (curMax < i) {
			result.emplace_back(i - l);
			curMax = i;
			l = i;
		}
		curMax = max(curMax, maxIdx[s[i] - 'a']);
	}
	result.emplace_back(s.size() - l);
	return result;
}
