#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::min;
using std::max;
using std::cout;
using std::endl;;
string Solution::stoneGameIII(vector<int>& stoneValue) {
	int size = stoneValue.size();
	vector<int> dp(size + 1, INT_MIN);
	dp.back() = 0;

	for (int i = size - 1 ; i >= 0 ; --i) {
		int sum = 0;

		for (int j = 0 ; j < min(3, size - i) ; ++j) {
			sum += stoneValue[i+j];
			dp[i] = max(dp[i], sum - dp[i+j+1]);
		}
	}
	if (dp[0] == 0) return "Tie";
	else if (dp[0] > 0) return "Alice";
	else return "Bob";
}
