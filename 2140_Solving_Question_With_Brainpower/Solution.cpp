#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::max;
using std::pair;
using std::priority_queue;

long long Solution::mostPoints(vector<vector<int>>& questions) {
	vector<long long> dp(questions.size(), 0);
	priority_queue<pair<int, long long>, vector<pair<int, long long>>, std::greater<pair<int, long long>>> pq;

	long long result = 0;
	long long curMax = 0;
	for (int i = 0 ; i < questions.size() ; ++i) {
		while (!pq.empty() && pq.top().first < i) {
			curMax = max(curMax, pq.top().second);
			pq.pop();
		}
		dp[i] = curMax + questions[i][0];
		pq.emplace(pair<int, long long>(i + questions[i][1], dp[i]));
		result = max(result, dp[i]);
	}
	return result;
}
