#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::pair;
using std::sort;

string Solution::rankTeams(vector<string>& votes) {
	if (votes.size() == 1) return votes[0];
	vector<vector<int>> cnt(26, vector<int>(27, 0));
	vector<bool> exists(26, false);
	for (int i = 0 ; i < 26 ; ++i) {
		cnt[i].back() = 25 - i;
	}


	for (const auto& v : votes) {
		for (int i = 0 ; i < v.size() ; ++i) {
			exists[v[i]-'A'] = exists[v[i]-'A'] | 1;
			++cnt[v[i]-'A'][i];
		}
	}

	sort(cnt.begin(), cnt.end(), std::greater<vector<int>>());

	string result;
	for (int i = 0 ; i < 26 ; ++i) {
		int curIdx = 25 - cnt[i].back();
		if (!exists[curIdx]) continue;
		result.push_back(curIdx + 'A');
	}
	return result;
}
