#include <Solution.h>
#include <iostream>
#include <map>

using std::map;
using std::to_string;

vector<string> Solution::findRelativeRanks(vector<int> &score) {
	map<int, int, std::greater<int>> m;

	for (int i = 0; i < score.size(); ++i) {
		m[score[i]] = i;
	}
	vector<string> result(score.size());
	int cnt = 1;
	for (const auto &e : m) {
		if (cnt == 1) {
			result[e.second] = "Gold Medal";
		} else if (cnt == 2) {
			result[e.second] = "Silver Medal";
		} else if (cnt == 3) {
			result[e.second] = "Bronze Medal";
		} else {
			result[e.second] = to_string(cnt);
		}
		++cnt;
	}
	return result;
}
