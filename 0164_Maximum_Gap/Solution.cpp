#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::min;

class Bucket {
	public:
		bool used = false;
		int minVal = INT_MAX;
		int maxVal = INT_MIN;
};

int Solution::BucketSort(vector<int>& nums) {
	if (nums.empty() && nums.size() < 2) return 0;

	int mini = *min_element(nums.begin(), nums.end());
	int maxi = *max_element(nums.begin(), nums.end());

	int bucketSize = max(1, (maxi - mini) / ((int) nums.size() - 1));
	int bucketNum = (maxi - mini) / bucketSize + 1;
	vector<Bucket> buckets(bucketNum);

	for (auto& val : nums) {
		int bucketIdx = (val - mini) / bucketSize;
		buckets[bucketIdx].used = true;
		buckets[bucketIdx].minVal = min(buckets[bucketIdx].minVal, val);
		buckets[bucketIdx].maxVal = max(buckets[bucketIdx].maxVal, val);
	}

	int prevBucketMax = mini, maxGap = 0;
	for (auto& bucket : buckets) {
		if (!bucket.used) continue;

		maxGap = max(maxGap, bucket.minVal - prevBucketMax);
		prevBucketMax = bucket.maxVal;
	}
	return maxGap;
}

// Radix Sort
int Solution::maximumGap(vector<int>& nums) {
	if (nums.size() < 2) return 0;
	vector<vector<int>> bucket(10, vector<int>());

	int div = 1;
	vector<int> next;
	for (int i = 0 ; i < 9 ; ++i) {
		for (const auto& val : nums) {
			int idx = (val / div) % 10;
			bucket[idx].emplace_back(val);
		}
		for (int i = 0 ; i < 10 ; ++i) {
			for (const auto& val : bucket[i]) {
				next.emplace_back(val);
			}
			bucket[i].clear();
		}
		nums = move(next);
		div *= 10;
	}
	int result = 0;
	for (int i = 0 ; i < nums.size() - 1 ; ++i) {
		result = max(result, nums[i+1] - nums[i]);
	}
	return result;
}
