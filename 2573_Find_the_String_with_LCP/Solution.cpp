#include <Solution.h>
#include <iostream>

string Solution::findTheString(vector<vector<int>>& lcp) {
	int size = lcp.size();
	string result(size, '0');
	char c = 'a';

	int i = 0;
	for ( ; c <= 'z' ; ++c) {
		while (i < size && result[i] != '0') {
			++i;
		}
		if (i == size) break;
		for (int j = 0 ; j < size ; ++j) {
			if (lcp[i][j] > 0) result[j] = c;
		}
	}
	for (const auto& c : result) if (c == '0') return "";

	vector<vector<int>> dp(size, vector<int>(size, 0));

	for (int i = size - 1 ; i >= 0 ; --i) {
		for (int j = size - 1 ; j >= 0 ; --j) {
			if (result[i] == result[j]) {
				dp[i][j] = i == size - 1 || j == size - 1 ? 1 : dp[i+1][j+1] + 1;
			}
			if (dp[i][j] != lcp[i][j]) return "";
		}
	}
	return result;
}
