#include <Solution.h>
#include <cmath>
// [0, 1,  2, 3]
// [1, 10, 1, 1]
// [0, 1]        1
//     [1, 2, 3] 10
//        [2, 3] 1
//           [3] 1
// dp[i] = dp[i-1] + prices[i];
int Solution::minimumCoins(vector<int>& prices) {
	int size = prices.size();
	deque<pair<int, long long>> deq;
	vector<long long> dp(size + 1, 0);

	for (int i = 1 ; i <= size ; ++i) {
		long long f = dp[i-1] + prices[i-1];

		while (!deq.empty() && deq.back().second >= f) {
			deq.pop_back();
		}
		deq.emplace_back(pair<int, long long>(i, f));

		// j + j >= i;
		// j >= (i / 2)
		int preLimit = (i + 1) / 2;
		while (!deq.empty() && deq.front().first < preLimit) {
			deq.pop_front();
		}
		dp[i] = deq.front().second;
	}
	return dp.back();
}
