#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <climits>

using std::cout;
using std::endl;
using std::min;
using std::set;
using std::unordered_map;

// pre half : i (2 ^ 15) => x
// post half : j = (n - i) (2 ^ 15) => y
// x+y = sum - (x+y)
// 2x + 2y = sum
// x+y = sum / 2;
// y = sum / 2 - x;

int getBitCnt(int v) {
	int cnt = 0;
	while (v) {
		++cnt;
		v = v & (v - 1);
	}
	return cnt;
}

void calculatePostSum(const vector<int> &nums, unordered_map<int, set<long long>> &m) {
	int size = 1 << nums.size();

	for (int bi = 0; bi < size; ++bi) {
		long long sum = 0;
		int bCnt = getBitCnt(bi);
		for (int i = 0; i < nums.size(); ++i) {
			if (bi & (1 << i)) {
				sum += (long long)nums[i];
			}
		}
		m[bCnt].emplace(sum);
	}
}

int Solution::minimumDifference(vector<int> &nums) {
	int n = nums.size() / 2;

	vector<int> preHalf(nums.begin(), nums.begin() + n);
	vector<int> postHalf(nums.begin() + n, nums.end());
	long long sum = 0;
	for (const auto &v : nums)
		sum += (long long)v;

	unordered_map<int, set<long long>> postSum;

	calculatePostSum(postHalf, postSum);

	long long result = INT_MAX;
	int size = 1 << n;
	for (int bi = 0; bi < size; ++bi) {
		int bCnt = getBitCnt(bi);
		long long preSum = 0;
		for (int i = 0; i < n; ++i) {
			if (bi & (1 << i)) {
				preSum += (long long)preHalf[i];
			}
		}
		auto idx = postSum[n - bCnt].lower_bound((sum >> 1) - preSum);
		if (idx != postSum[n - bCnt].end()) {
			result = min(result, std::abs(sum - ((preSum + *idx) << 1)));
		}
		if (idx != postSum[n - bCnt].begin()) {
			idx = prev(idx);
			result = min(result, std::abs(sum - ((preSum + *idx) << 1)));
		}
	}
	return result;
}
