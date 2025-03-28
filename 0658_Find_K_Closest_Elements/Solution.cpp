#include <Solution.h>
#include <iostream>

vector<int> Solution::findClosestElements(vector<int> &arr, int k, int x) {
	auto idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

	vector<int> result;
	auto prev = idx, next = idx;
	while ((next - prev) <= k) {
		if (prev == -1) {
			++next;
		} else if (next == arr.size()) {
			--prev;
		} else {
			int pDiff = abs(arr[prev] - x);
			int nDiff = abs(arr[next] - x);
			if (pDiff <= nDiff) {
				--prev;
			} else {
				++next;
			}
		}
	}
	for (int i = prev + 1; i < next; ++i)
		result.emplace_back(arr[i]);
	return result;
}
