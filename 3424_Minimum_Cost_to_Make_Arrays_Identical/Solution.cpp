#include <Solution.h>
#include <iostream>
#include <algorithm>

long long Solution::minCost(vector<int>& arr, vector<int>& brr, long long k) {
	long long ori_diff = 0;
	for (int i = 0 ; i < arr.size() ; ++i) {
		ori_diff += (abs(arr[i] - brr[i]));
	}

	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	long long result = 0;
	for (int i = 0 ; i < arr.size() ; ++i) {
		result += (abs(arr[i] - brr[i]));
	}
	return min(result + k, ori_diff);
}
