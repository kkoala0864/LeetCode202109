#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

bool Solution::checkInclusion2(string s1, string s2) {
	if (s1.size() > s2.size()) return false;
	vector<int> map(26, -1);
	for (const auto& iter : s1) {
		if (map[iter-'a'] > 0) {
			++map[iter-'a'];
		} else {
			map[iter-'a'] = 1;
		}
	}

	int iter = 0;
	int start = 0;
	int cnt = s1.size();
	vector<int> cmp = map;
	while (iter < s2.size()) {
		int idx = s2[iter] - 'a';
		if (cmp[idx] == -1) {
			cnt = s1.size();
			cmp = map;
			start = iter + 1;
		} else {
			while (cmp[idx] == 0) {
				++cmp[s2[start++]-'a'];
				++cnt;
			}
			--cmp[idx];
			--cnt;
		}
		++iter;
		if (cnt == 0) return true;

	}
	return false;
}
