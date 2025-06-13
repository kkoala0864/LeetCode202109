#include <Solution.h>

int check(vector<int>& nums, int maxV, int p) {
	int cnt = 0;
	for (int i = 0 ; i < nums.size() - 1 ; ++i) {
		if (abs(nums[i] - nums[i+1]) <= maxV) {
			++cnt;
			++i;
		}
	}
	return cnt >= p;
}

int Solution::minimizeMax(vector<int>& nums, int p) {
	if (p == 0) return 0;
	sort(nums.begin(), nums.end());
	int l = 0 , r = nums.back();
	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		if (check(nums, mid, p)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}
// find minimum maximum difference
// cur diff <= dp[] = dp[]
// cur diff > dp[] => cur, diff

/*
int Solution::minimizeMax(vector<int>& nums, int p) {
	sort(nums.begin(), nums.end());
	int size = nums.size();
	vector<int> dp(1, INT_MAX);

	for (int i = 1 ; i < size ; ++i) {
		dp.emplace_back(min(dp[i-1], nums[i] - nums[i-1]));
	}

	for (int i = 1 ; i < p ; ++i) {
		vector<int> next(nums.size(), INT_MAX);
		for (int j = 2 * i ; j < nums.size() - 1 ; ++j) {
			next[j + 1] = min(next[j], max(dp[j-1], abs(nums[j + 1] - nums[j])));
		}
		dp = std::move(next);
	}
	return dp.back();
}*/
