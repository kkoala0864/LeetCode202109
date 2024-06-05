#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;

vector<string> Solution::commonChars(vector<string>& words) {
	vector<vector<int>> cnt(words.size(), vector<int>(26, 0));

	for (int i = 0 ; i < words.size() ; ++i) {
		for (const auto& c : words[i]) {
			++cnt[i][c-'a'];
		}
	}
	vector<string> result;
	for (int i = 0 ; i < 26 ; ++i) {
		int v = INT_MAX;
		for (int j = 0 ; j < words.size() ; ++j) {
			v = min(v, cnt[j][i]);
		}
		for (int k = 0 ; k < v ; ++k) {
			result.emplace_back(string(1, i + 'a'));
		}
	}
	return result;
}
