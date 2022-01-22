#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

/*
bool Solution::winnerSquareGame(int n) {
	vector<bool> dp(n+1, false);

	dp[1] = true;
	for (int i = 2 ; i <= n ; ++i) {
		bool result = false;
		for (int j = 1 ; (j * j) <= i ; ++j) {
			result |= !dp[i-(j*j)];
		}
		dp[i] = result;
	}
	return dp[n];
}*/



bool Solution::winnerSquareGame(int n) {
	vector<bool> dp(n+1, false);

	dp[1] = true;
	for (int i = 0 ; i <= n ; ++i) {
		if (dp[i]) continue;
		for (int j = 1 ; (i + j*j) <= n ; ++j) dp[i+j*j] = true;
	}
	return dp[n];
}
