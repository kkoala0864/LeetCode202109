#include <Solution.h>

int Solution::maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
	unordered_map<char, int> scores;
	vector<int> lCnt(26, 0);
	for (int i = 0 ; i < letters.size() ; ++i) {
		++lCnt[letters[i]-'a'];
		scores[letters[i]] = score[letters[i]-'a'];
	}
	vector<vector<int>> comb;
	for (const auto& w : words) {
		auto tmpCnt = lCnt;
		vector<int> cur(27, 0);
		for (const auto& c : w) {
			++cur[c-'a'];
			if (scores.count(c) == 0 || tmpCnt[c-'a'] == 0) {
				cur[26] = 0;
				break;
			} else {
				--tmpCnt[c-'a'];
				cur[26] += scores[c];
			}
		}
		if (cur[26] > 0) {
			comb.emplace_back(cur);
		}
	}
	int size = comb.size();
	int result = 0;
	for (int i = 1 ; i < (1 << size) ; ++i) {
		vector<int> cnt(27, 0);
		int curSum = 0;
		int j = 0;
		for (; j < size ; ++j) {
			if ((i & (1 << j)) == 0) continue;
			int k = 0;
			for (; k < 26 ; ++k) {
				cnt[k] += comb[j][k];
				if (cnt[k] > lCnt[k]) break;
			}
			if (k < 26) break;
			curSum += comb[j][26];
		}
		if (j < size) continue;
		result = max(result, curSum);
	}
	return result;
}
