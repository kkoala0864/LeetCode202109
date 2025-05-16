#include <Solution.h>

int getDis(const string& lhs, const string& rhs) {
	int size = lhs.size();
	int diff = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (lhs[i] != rhs[i]) ++diff;
	}
	return diff;
}

vector<string> Solution::getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
	vector<pair<int, int>> preStr;

	int resultLen = 0;
	int resultIdx = 0;
	for (int i = 0 ; i < groups.size() ; ++i) {
		int maxLen = 0;
		int pi = -1;
		for (int j = i - 1 ; j >= 0 ; --j) {
			if (groups[i] == groups[j]) continue;
			if (words[i].size() != words[j].size()) continue;
			if (getDis(words[i], words[j]) != 1) continue;
			if (maxLen < preStr[j].first) {
				maxLen = preStr[j].first;
				pi = j;
			}
		}
		preStr.emplace_back(pair<int, int>(maxLen + 1, pi));
		if (preStr[i].first > resultLen) {
			resultLen = preStr[i].first;
			resultIdx = i;
		}
	}

	vector<string> result;
	int idx = resultIdx;
	while (idx != -1) {
		result.emplace_back(words[idx]);
		idx = preStr[idx].second;
	}
	reverse(result.begin(), result.end());
	return result;
}
