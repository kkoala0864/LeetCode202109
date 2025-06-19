#include <Solution.h>

bool isSub(const string& lhs, const string& rhs) {
	if (lhs.size() > rhs.size()) return false;
	int li = 0;
	for (int i = 0 ; i < rhs.size() ; ++i) {
		if (lhs[li] == rhs[i]) {
			++li;
		}
		if (li == lhs.size()) return true;
	}
	return li == lhs.size();
}

// if a is b's subsequence, then no need to check a's subsequence, because a's subsequence must be b's subsequence
// if a is not b's subsequence, then a is the longest uncommon subsequence
int Solution::findLUSlength(vector<string>& strs) {
	auto cmp = [](const string& lhs, const string& rhs) {
		return lhs.size() > rhs.size();
	};
	sort(strs.begin(), strs.end(), cmp);
	for (int i = 0 ; i < strs.size() ; ++i) {
		bool find = false;
		for (int j = 0 ; j < strs.size() ; ++j) {
			if (i == j) continue;
			if (isSub(strs[i], strs[j])) {
				find = true;
				break;
			}
		}

		if (!find) return strs[i].size();
	}
	return -1;

}
