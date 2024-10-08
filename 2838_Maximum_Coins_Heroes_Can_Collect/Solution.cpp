#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::pair;

vector<long long> Solution::maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
	vector<long long> result;

	vector<pair<int, int>> mToc;
	for (int i = 0 ; i < monsters.size() ; ++i) {
		mToc.emplace_back(pair<int, int>(monsters[i], coins[i]));
	}

	sort(mToc.begin(), mToc.end());

	vector<long long> preSum;
	long long cur = 0;
	for (int i = 0 ; i < monsters.size() ; ++i) {
		cur += (long long)mToc[i].second;
		monsters[i] = mToc[i].first;
		preSum.emplace_back(cur);
	}


	for (int i = 0 ; i < heroes.size() ; ++i) {
		int idx = upper_bound(monsters.begin(), monsters.end(), heroes[i]) - monsters.begin();
		if (idx != 0) {
			result.emplace_back(preSum[idx-1]);
		} else {
			result.emplace_back(0);
		}
	}
	return result;
}
