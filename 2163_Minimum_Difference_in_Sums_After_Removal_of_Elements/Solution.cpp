#include <Solution.h>

long long Solution::minimumDifference(vector<int>& nums) {
	int size = nums.size();
	int n = size / 3;

	priority_queue<long long, vector<long long>, greater<>> minH;
	priority_queue<long long> maxH;

	vector<long long> preMin(size, LLONG_MAX), postMax(size, LLONG_MIN);

	long long sum = 0;
	for (int i = 0 ; i < 2 * n ; ++i) {
		sum += nums[i];
		maxH.emplace(nums[i]);
		while (maxH.size() > n) {
			sum -= maxH.top();
			maxH.pop();
		}
		if (i >= n-1) {
			preMin[i] = sum;
		}
	}
	sum = 0;
	for (int i = nums.size() - 1 ; i >= n ; --i) {
		sum += nums[i];
		minH.emplace(nums[i]);
		while (minH.size() > n) {
			sum -= minH.top();
			minH.pop();
		}
		if (i >= n-1) {
			postMax[i] = sum;
		}
	}

	long long result = LLONG_MAX;
	for (int i = n - 1 ; i < (size - n) ; ++i) {
		result = min(result, preMin[i] - postMax[i+1]);
	}
	return result;
}
