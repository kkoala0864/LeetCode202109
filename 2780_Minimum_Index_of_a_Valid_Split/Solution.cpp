#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

int Solution::minimumIndex(vector<int> &nums) {
	int size = nums.size();
	unordered_map<int, int> count;
	int dominate = 0;
	for (const auto &v : nums) {
		++count[v];
		if (count[v] > (nums.size() >> 1)) {
			dominate = v;
		}
	}

	int result = size;
	int curCnt = 0;
	for (int i = 0; i < size; ++i) {
		if (nums[i] == dominate)
			++curCnt;
		int postSize = size - i - 1;
		int restCnt = count[dominate] - curCnt;
		if (((curCnt << 1) > (i + 1)) && ((restCnt << 1) > postSize)) {
			result = i;
			break;
		}
	}

	return result == size ? -1 : result;
}
