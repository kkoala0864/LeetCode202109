#include <Solution.h>

vector<string> Solution::getLongestSubsequence(vector<string>& words, vector<int>& groups) {
	vector<vector<string>> result(2, vector<string>());

	for (int i = 0 ; i < words.size() ; ++i) {
		int cur = groups[i];
		int opcur = groups[i] == 0 ? 1 : 0;
		result[cur] = result[opcur];
		result[cur].emplace_back(words[i]);
	}
	return result[0].size() > result[1].size() ? result[0] : result[1];
}
