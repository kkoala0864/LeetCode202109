#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;
using std::cout;
using std::endl;

int Solution::longestIdealString(string s, int k) {
	vector<int> dp(s.size() + 1, 0);
	vector<int> lastIdx(26, 0);

	int size = s.size();
	int result = 0;
	for (int i = 0 ; i < size ; ++i) {
		int cur = s[i] - 'a';
		for (int ci = max(0, cur - k) ; ci <= min(cur+k, 25) ; ++ci) {
			dp[i+1] = max(dp[i+1], dp[lastIdx[ci]] + 1);
		}
		lastIdx[cur] = i + 1;
		result = max(result, dp[i+1]);
	}
	return result;
}
