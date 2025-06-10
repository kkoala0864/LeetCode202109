#include <Solution.h>

int Solution::countRangeSum(vector<int>& nums, int lower, int upper) {
	BTree* bt = new BTree();
	long long sum = 0;
	long long result = 0;

	long long maxV = LLONG_MIN;
	long long minV = LLONG_MAX;
	for (const auto& v : nums) {
		sum += v;
		minV = min(minV, sum);
		maxV = max(maxV, sum);
	}
	sum = 0;

	for (const auto& v : nums) {
		sum += v;
		if (lower <= sum && sum <= upper) ++result;
		long long lv = sum - lower;
		long long uv = sum - upper;
		long long ret = bt->query(min(lv, uv), max(lv, uv), minV, maxV);
		result += ret;
		bt->update(sum, 1, minV, maxV);
	}
	return result;
}
