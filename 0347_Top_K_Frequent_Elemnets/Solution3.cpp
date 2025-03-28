#include <Solution.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using std::priority_queue;
using std::swap;
using std::unordered_map;

int partition(int left, int right, int pivot_idx, vector<int> &unique, unordered_map<int, int> &cnt) {
	int pivot_frequency = cnt[unique[pivot_idx]];
	swap(unique[pivot_idx], unique[right]);

	int store_index = left;
	for (int i = left; i <= right; i++) {
		if (cnt[unique[i]] < pivot_frequency) {
			swap(unique[store_index], unique[i]);
			++store_index;
		}
	}
	swap(unique[right], unique[store_index]);
	return store_index;
}

void quickselect(int left, int right, int k_smallest, vector<int> &unique, unordered_map<int, int> &cnt) {
	if (left == right)
		return;
	int pivot_index = left + rand() % (right - left + 1);
	pivot_index = partition(left, right, pivot_index, unique, cnt);
	if (k_smallest == pivot_index) {
		return;
	} else if (k_smallest < pivot_index) {
		quickselect(left, pivot_index - 1, k_smallest, unique, cnt);
	} else {
		quickselect(pivot_index + 1, right, k_smallest, unique, cnt);
	}
}

vector<int> Solution::topKFrequent3(vector<int> &nums, int k) {
	unordered_map<int, int> cnt;
	for (const auto &iter : nums)
		++cnt[iter];
	vector<int> unique;
	for (const auto &iter : cnt)
		unique.emplace_back(iter.first);

	int n = unique.size();
	quickselect(0, n - 1, n - k, unique, cnt);

	vector<int> result(k);
	copy(unique.begin() + n - k, unique.end(), result.begin());
	return result;
}
