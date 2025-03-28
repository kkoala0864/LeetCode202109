#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool Solution::checkInclusion(string s1, string s2) {
	vector<int> map(26, 0);
	if (s1.size() > s2.size())
		return false;

	for (const auto &iter : s1)
		++map[iter - 'a'];

	int end = 0;
	while (end < s2.size()) {
		if (map[s2[end] - 'a'] == 0) {
			++end;
			continue;
		}

		vector<int> compare = map;
		int start = end;
		while (end < s2.size() && (end - start + 1) <= s1.size()) {
			if (map[s2[end] - 'a'] == 0)
				break;
			--compare[s2[end] - 'a'];
			if (compare[s2[end] - 'a'] < 0) {
				while (compare[s2[end] - 'a'] < 0) {
					++compare[s2[start] - 'a'];
					++start;
				}
			}
			++end;
		}
		if ((end - start + 1) > s1.size())
			return true;
	}
	return false;
}
