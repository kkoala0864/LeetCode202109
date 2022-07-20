#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::upper_bound;

int Solution::numMatchingSubseq(string s, vector<string>& words) {
	vector<vector<int>> iVec(26, vector<int>());

	for (int i = 0 ; i < s.size() ; ++i) iVec[s[i]-'a'].emplace_back(i);

	int result = 0;
	for (const auto& w : words) {
		int cIdx = -1;
		bool flag = true;
		for (const auto& c : w) {
			if (iVec[c-'a'].empty()) {
				flag = false;
				break;
			} else {
				auto it = upper_bound(iVec[c-'a'].begin(), iVec[c-'a'].end(), cIdx);
				if (it == iVec[c-'a'].end()) {
					flag = false;
					break;
				} else {
					cIdx = *it;
				}
			}
		}
		if (flag) ++result;
	}
	return result;
}
