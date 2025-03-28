#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::max;
using std::min;

vector<int> Solution::partitionLabels(string s) {
	vector<int> uMap(26, INT_MIN);

	for (int i = 0; i < s.size(); ++i)
		uMap[s[i] - 'a'] = max(uMap[s[i] - 'a'], i);

	vector<int> result;
	int start = 0;
	int boundary = uMap[s[0] - 'a'];
	for (int i = 0; i < s.size(); ++i) {
		boundary = max(boundary, uMap[s[i] - 'a']);
		if (i == boundary) {
			result.emplace_back(boundary - start + 1);
			start = boundary + 1;
		}
	}
	return result;
}
