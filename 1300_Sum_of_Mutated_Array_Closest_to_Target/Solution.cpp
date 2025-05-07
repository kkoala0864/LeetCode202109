#include <Solution.h>

int check(vector<int>& arr, vector<int>& preSum, int mid) {
	int idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
	if (idx == arr.size()) {
		return preSum.back();
	}

	int num = arr.size() - idx;
	int last = idx == 0 ? 0 : preSum[idx - 1];
	int sum = last + (num * mid);
	return sum;
}

int Solution::findBestValue(vector<int>& arr, int target) {
	sort(arr.begin(), arr.end());
	vector<int> preSum(1, arr[0]);

	for (int i = 1 ; i < arr.size() ; ++i) {
		preSum.emplace_back(preSum.back() + arr[i]);
	}

	int l = 0, r = arr.back();
	int mid = 0;

	while (l < r) {
		mid = r - ((r - l) >> 1);

		int v = check(arr, preSum, mid);
		if (v <= target) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}

	int lv = check(arr, preSum, l);
	int lpv = check(arr, preSum, l + 1);
	return abs(target - lv) <= abs(target - lpv) ? l : l + 1;
}

// TC : O(nlogn) + O(loglogn)
