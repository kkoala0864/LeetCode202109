#include <Solution.h>
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

int Solution::minDeletions(string s) {
	vector<int> freq(26, 0);
	for (const auto& c: s) ++freq[c-'a'];
	map<int, int, std::greater<int>> oMap;
	for (const auto& v : freq) if (v > 0) ++oMap[v];

	int result = 0;
	for (auto& ele : oMap) {
		if (ele.second == 1) continue;
		int shift = ele.second - 1;
		int idx = ele.first - 1;

		while (shift > 0 && idx >= 0) {
			result += shift;
			if (oMap[idx] == 0) {
				oMap[idx] = 1;
				--shift;
			}
			--idx;
		}
	}
	return result;
}
