#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

int Solution::firstUniqChar(string s) {
	vector<vector<int>> cnt(26, vector<int>());

	for (int i = 0 ; i < s.size() ; ++i) {
		cnt[s[i]-'a'].emplace_back(i);
	}
	int result = s.size();

	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i].size() == 1) {
			result = min(result, cnt[i][0]);
		}
	}
	return result == s.size() ? -1 : result;
}
