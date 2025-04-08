#include <Solution.h>
#include <iostream>
#include <vector>
#include <climits>

int getBS(vector<int>& cnt) {
	int maxCnt = 0;
	int minCnt = INT_MAX;
	for (int i = 0 ; i < 26 ; ++i) {
		if (cnt[i] == 0) continue;
		maxCnt = max(maxCnt, cnt[i]);
		minCnt = min(minCnt, cnt[i]);
	}
	return maxCnt - minCnt;
}

int Solution::beautySum(string s) {
	int sum = 0;

	for (int i = 3 ; i <= s.size() ; ++i) {
		vector<int> cnt(26, 0);
		for (int j = 0 ; j < s.size() ; ++j) {
			++cnt[s[j]-'a'];
			if (j >= i) {
				--cnt[s[j-i]-'a'];
			}
			if (j >= i - 1) {
				sum += getBS(cnt);
			}
		}
	}
	return sum;
}
