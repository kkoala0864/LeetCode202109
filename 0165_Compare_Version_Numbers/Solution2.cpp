#include <Solution.h>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int Solution::compareVersion2(string version1, string version2) {
	int idx1 = 0, idx2 = 0;

	while (idx1 < version1.size() || idx2 < version2.size()) {
		string s1, s2;
		while (idx1 < version1.size() && version1[idx1] != '.') {
			s1.push_back(version1[idx1]);
			++idx1;
		}
		++idx1;
		while (idx2 < version2.size() && version2[idx2] != '.') {
			s2.push_back(version2[idx2]);
			++idx2;
		}
		++idx2;

		int val1 = 0, val2 = 0;
		val1 = s1.empty() ? 0 : stoi(s1);
		val2 = s2.empty() ? 0 : stoi(s2);
		if (val1 == val2) continue;
		return val1 < val2 ? -1 : 1;
	}
	return 0;
}
