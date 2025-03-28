#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::upper_bound;

int Solution::numMatchingSubseq2(string s, vector<string> &words) {
	vector<vector<const char *>> vec(26, vector<const char *>());

	for (const auto &w : words) {
		vec[w[0] - 'a'].emplace_back(w.c_str());
	}

	int result = 0;
	for (const auto &c : s) {
		auto cur = vec[c - 'a'];
		vec[c - 'a'].clear();
		for (auto &w : cur) {
			const char *a = w + 1;
			if (*a == '\0')
				++result;
			else {
				vec[*a - 'a'].emplace_back(a);
			}
		}
	}
	return result;
}

int Solution::numMatchingSubseq(string s, vector<string> &words) {
	vector<vector<int>> iVec(26, vector<int>());

	for (int i = 0; i < s.size(); ++i)
		iVec[s[i] - 'a'].emplace_back(i);

	int result = 0;
	for (const auto &w : words) {
		int cIdx = -1;
		bool flag = true;
		for (const auto &c : w) {
			if (iVec[c - 'a'].empty()) {
				flag = false;
				break;
			} else {
				auto it = upper_bound(iVec[c - 'a'].begin(), iVec[c - 'a'].end(), cIdx);
				if (it == iVec[c - 'a'].end()) {
					flag = false;
					break;
				} else {
					cIdx = *it;
				}
			}
		}
		if (flag)
			++result;
	}
	return result;
}
