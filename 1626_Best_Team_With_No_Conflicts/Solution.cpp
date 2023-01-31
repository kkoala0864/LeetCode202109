#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::greater;
using std::pair;
using std::max;

int Solution::bestTeamScore(vector<int>& scores, vector<int>& ages) {
	vector<pair<int, int>> list;
	int size = scores.size();
	for (int i = 0 ; i < size ; ++i) {
		list.emplace_back(pair<int, int>(ages[i], scores[i]));
	}
	sort(list.begin(), list.end(), greater<pair<int, int>>());

	int result = 0;
	vector<int> dp(size, 0);
	for (int i = 0 ; i < size ; ++i) {
		int local = 0;
		for (int j = 0 ; j < i ; ++j) {
			if ((list[j].first > list[i].first && list[j].second >= list[i].second)
			 || (list[j].first == list[i].first)) {
				local = max(local, dp[j]);
			}
		}
		dp[i] = local + list[i].second;
		result = max(result, dp[i]);
	}
	return result;
}
