#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

int Solution::findContentChildren(vector<int>& g, vector<int>& s) {
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int sIdx = 0;
	int result = 0;
	for (const auto& v : g) {
		for (; sIdx < s.size() ; ++sIdx) {
			if (s[sIdx] >= v) break;
		}
		if (sIdx == s.size()) break;
		++result;
		++sIdx;
	}
	return result;
}

