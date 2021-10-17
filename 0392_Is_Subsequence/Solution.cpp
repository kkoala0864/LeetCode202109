#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::isSubsequence(string s, string t) {
	vector<vector<int>> uMap(26, vector<int>());

	for (int i = 0 ; i < t.size() ; ++i) uMap[t[i]-'a'].emplace_back(i);

	int idx = -1;
	for (int i = 0 ; i < s.size() ; ++i) {
		bool find = false;
		for (const auto& nextIdx : uMap[s[i]-'a']) {
			if (nextIdx > idx) {
				idx = nextIdx;
				find = true;
				break;
			}
		}
		if (!find) return false;
	}
	return true;
}
