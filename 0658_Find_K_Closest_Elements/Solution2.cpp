#include <Solution.h>
#include <iostream>
#include <climits>

using std::cout;
using std::endl;

vector<int> Solution::findClosestElements2(vector<int>& arr, int k, int x) {
	int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

	int sIdx = idx - 1;
	int bIdx = idx;

	vector<int> result;
	while ((bIdx - sIdx) <= k) {
		int sValDiff = sIdx == -1 ? INT_MAX : abs(arr[sIdx] - x);
		int bValDiff = bIdx == arr.size() ? INT_MAX : abs(arr[bIdx] - x);

		if (sValDiff <= bValDiff) {
			--sIdx;
		} else {
			++bIdx;
		}
	}
	for(int i = sIdx + 1 ; i < bIdx ; ++i) {
		result.emplace_back(arr[i]);
	}
	return result;
}
