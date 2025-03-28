#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;

void dfs(vector<string> &arr, int idx, int bitmask, int size, int &result) {
	if (idx == arr.size()) {
		result = max(result, size);
		return;
	}
	for (int i = idx; i < arr.size(); ++i) {
		int nextBitMask = bitmask;
		int ci = 0;
		for (; ci < arr[i].size(); ++ci) {
			if (nextBitMask >> (arr[i][ci] - 'a') & 1)
				break;
			else
				nextBitMask |= 1 << (arr[i][ci] - 'a');
		}
		if (ci != arr[i].size())
			dfs(arr, i + 1, bitmask, size, result);
		else
			dfs(arr, i + 1, nextBitMask, size + arr[i].size(), result);
	}
}

int Solution::maxLength(vector<string> &arr) {
	int bitmask = 0;
	int result = 0;
	int size = 0;
	dfs(arr, 0, bitmask, size, result);
	return result;
}
