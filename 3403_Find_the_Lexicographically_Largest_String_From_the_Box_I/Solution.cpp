#include <Solution.h>

string Solution::answerString(string word, int numFriends) {
	if (numFriends == 1) return word;
	string result;
	vector<vector<int>> idxs(26, vector<int>());

	int maxIdx = -1;
	for (int i = 0 ; i < word.size() ; ++i) {
		idxs[word[i]-'a'].emplace_back(i);
		maxIdx = max(maxIdx, word[i]-'a');
	}

	for (const auto& i : idxs[maxIdx]) {
		string cur;
		if (i >= (numFriends - 1)) {
			cur = word.substr(i);
		} else {
			int size = word.size() - i - (numFriends - 1 - i);
			cur = word.substr(i, size);
		}
		result = max(result, cur);
	}
	return result;
}
