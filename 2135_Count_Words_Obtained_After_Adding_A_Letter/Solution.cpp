#include <Solution.h>
#include <iostream>
#include <unordered_set>
using std::unordered_set;

int cnt(const string &str) {
	int result = 0;
	for (const auto &iter : str) {
		int idx = iter - 'a';
		result |= (1 << idx);
	}
	return result;
}

int Solution::wordCount(vector<string> &startWords, vector<string> &targetWords) {
	unordered_set<int> uSet;
	for (const auto &str : startWords)
		uSet.emplace(cnt(str));

	int result = 0;
	for (const auto &str : targetWords) {
		int target = cnt(str);
		for (int i = 0; i < str.size(); ++i) {
			int removeIdx = str[i] - 'a';
			int mask = target & ~(1 << removeIdx);
			if (uSet.count(mask)) {
				++result;
				break;
			}
		}
	}
	return result;
}
