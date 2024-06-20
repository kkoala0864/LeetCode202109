#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cout;
using std::endl;

int getBou(const vector<int>& b, int k, int d) {
	int cnt = 0;
	int result = 0;

	for (const auto& v : b) {
		if (v <= d) {
			++cnt;
		} else {
			result += (cnt / k);
			cnt = 0;
		}
	}
	result += (cnt/k);
	return result;
}

int Solution::minDays(vector<int>& bloomDay, int m, int k) {
	long size = bloomDay.size();
	if (((long)m * (long)k) > size) return -1;

	vector<int> list = bloomDay;
	sort(list.begin(), list.end());

	int l = 0, r = size - 1, mid = 0;
	int bou = 0;
	while (l < r) {
		mid = l + ((r - l) >> 1);
		bou = getBou(bloomDay, k, list[mid]);
		if (bou < m) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	bou = getBou(bloomDay, k, list[l]);
	return bou >= m ? list[l] : -1;
}
