#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

double Solution::probabilityOfHeads(vector<double>& prob, int target) {
	int size = prob.size();
	vector<unordered_map<int, double>> dp(size, unordered_map<int ,double>());

	dp[0][0] = 1 - prob[0];
	dp[0][1] = prob[0];

	for (int i = 1 ; i < size ; ++i) {
		for (const auto& iter : dp[i-1]) {
			if (iter.first < target) dp[i][iter.first + 1] += (iter.second * prob[i]);
			dp[i][iter.first] += (iter.second * (1 - prob[i]));
		}
	}

	return dp.back().count(target) ? dp.back()[target] : 0;
}
