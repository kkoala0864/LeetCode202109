#include <Solution.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using std::priority_queue;
using std::vector;
using std::pair;
using std::greater;

int Solution::nthUglyNumber2(int n) {
	vector<int> dpIdx(3, 0);
	vector<int> v = {2, 3, 5};
	vector<int> dp = {1};

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0 ; i < 3 ; ++i) {
		pq.emplace(pair<int, int>(v[i] * dp[dpIdx[i]], i));
	}

	while (dp.size() < n) {
		int curV = pq.top().first;
		int idx = pq.top().second;
		pq.pop();

		if (dp.back() != curV) dp.emplace_back(curV);
		++dpIdx[idx];
		pq.emplace(pair<int, int>(v[idx] * dp[dpIdx[idx]], idx));
	}
	return dp.back();
}
