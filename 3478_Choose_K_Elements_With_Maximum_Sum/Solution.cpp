#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <queue>

using std::pair;
using std::priority_queue;
using std::sort;

vector<long long> Solution::findMaxSum(vector<int> &nums1, vector<int> &nums2, int k) {
	int size = nums1.size();
	vector<long long> result(size, 0);

	vector<pair<int, int>> vToIdx;

	for (int i = 0; i < size; ++i) {
		vToIdx.emplace_back(pair<int, int>(nums1[i], i));
	}
	sort(vToIdx.begin(), vToIdx.end());

	priority_queue<int, vector<int>, std::greater<>> minHeap;
	long long sum = 0;
	for (int i = 0; i < size; ++i) {
		int idx = vToIdx[i].second;
		if (i > 0) {
			if (vToIdx[i].first == vToIdx[i - 1].first) {
				result[idx] = result[vToIdx[i - 1].second];
			} else {
				result[idx] = sum;
			}
		}
		minHeap.emplace(nums2[idx]);
		sum += (long long)nums2[idx];
		while (minHeap.size() > k) {
			sum -= (long long)minHeap.top();
			minHeap.pop();
		}
	}
	return result;
}
