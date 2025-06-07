#include <Solution.h>

string Solution::clearStars(string s) {
	vector<vector<int>> charToIdx(26, vector<int>());

	for (int i = 0 ; i < s.size() ; ++i) {
		if (s[i] == '*') {
			for (int i = 0 ; i < 26 ; ++i) {
				if (charToIdx[i].empty()) continue;
				charToIdx[i].pop_back();
				break;
			}
		} else {
			charToIdx[s[i]-'a'].emplace_back(i);
		}
	}
	vector<pair<int, int>> idxs;
	for (int i = 0 ; i < 26 ; ++i) {
		for (const auto& idx : charToIdx[i]) {
			idxs.emplace_back(pair<int, int>(idx, i));
		}
	}
	sort(idxs.begin(), idxs.end());
	string result;
	for (const auto& i : idxs) {
		result.push_back(i.second + 'a');
	}
	return result;
}
