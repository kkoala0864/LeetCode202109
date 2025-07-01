#include <Solution.h>

int gcd(int v1, int v2) {
	if (v1 < v2) swap(v1, v2);
	if (v2 == 0) return v1;

	v1 %= v2;
	return gcd(v2, v1);
}

// state compression
int Solution::maxScore(vector<int>& nums) {
	unordered_map<int, int> state;
	int size = nums.size();
	for (int i = 0 ; i < size ; ++i) {
		for (int j = i + 1 ; j < size ; ++j) {
			int mask = (1 << i) | (1 << j);
			state[mask] = gcd(nums[i], nums[j]);
		}
	}

	unordered_map<int, int> dp;
	dp[0] = 0;
	for (int i = 0 ; i < (size / 2) ; ++i) {
		unordered_map<int, int> next;
		for (const auto& e : dp) {
			for (const auto& s : state) {
				if (e.first & s.first) continue;
				int mask = e.first | s.first;
				next[mask] = max(next[mask], e.second + (s.second * (i + 1)));
			}
		}
		dp = move(next);
	}
	return dp[(1 << size) - 1];
}
