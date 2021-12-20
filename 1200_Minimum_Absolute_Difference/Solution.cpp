#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;
using std::min;

vector<vector<int>> Solution::minimumAbsDifference(vector<int>& arr) {
	int size = 2 * 1000000 + 1;
	int offset = 1000000;
	vector<bool> record(size, false);
	int start = INT_MAX;
	for (const auto& iter : arr) {
		record[iter+offset] = true;
		start = min(start, iter+offset);
	}

	int last = start;
	arr[0] = last - offset;
	int cnt = 0;
	int minDiff = INT_MAX;
	for (int i = last + 1 ; i < size ; ++i) {
		if (record[i]) {
			minDiff = min(i - last, minDiff);
			last = i;
			++cnt;
			arr[cnt] = i - offset;
			if (cnt == arr.size()-1) break;
		}
	}

	vector<vector<int>> result;
	for (int i = 1 ; i < arr.size() ; ++i) {
		if ((arr[i] - arr[i-1]) == minDiff) {
			result.push_back({arr[i-1], arr[i]});
		}
	}
	return result;
}
