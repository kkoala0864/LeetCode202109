#include <Solution.h>

long long Solution::maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
	long long sum = 0;

	vector<long long> post, neg;
	for (int i = 0 ; i < nums.size() ; ++i) {
		sum += nums[i];
		int diff = (nums[i] ^ k) - nums[i];
		if (diff >= 0) post.emplace_back(diff);
		else neg.emplace_back(diff);
	}

	sort(post.begin(), post.end());
	sort(neg.begin(), neg.end());
	sum = accumulate(post.begin(), post.end(), sum);

	if ((post.size() & 1) == 0) {
		return sum;
	}
	long long result = sum - post[0];
	if (!neg.empty()) {
		result = max(result, sum + neg.back());
	}

	return result;
}
