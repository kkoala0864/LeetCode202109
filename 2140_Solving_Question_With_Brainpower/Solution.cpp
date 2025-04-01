#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

long long Solution::mostPoints(vector<vector<int>> &questions) {
	vector<long long> dp(questions.size() + 1, 0);

	for (int i = questions.size() - 1; i >= 0; --i) {
		int nextIdx = i + questions[i][1] + 1;
		dp[i] = max(questions[i][0] + (nextIdx >= questions.size() ? 0 : dp[nextIdx]), dp[i + 1]);
	}
	return dp[0];
}
