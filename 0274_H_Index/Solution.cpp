#include <Solution.h>
#include <iostream>
#include <algorithm>
#include <climits>

using std::sort;
using std::max;
using std::min;

int Solution::hIndex(vector<int>& citations) {
	int maxVal = INT_MIN;
	sort(citations.begin(), citations.end());
	int size = citations.size();
	for (int i = size - 1 ; i >= 0 ; --i) {
		int biggerNo = size-i;
		int hidx = min(biggerNo, citations[i]);
		maxVal = max(maxVal, hidx);
	}
	return maxVal;
}
