#include <Solution.h>
#include <iostream>

vector<int> Solution::twoSum(vector<int>& numbers, int target) {
	int l = 0, r = numbers.size() - 1;
	while (l < r) {
		int val = numbers[l] + numbers[r];
		if (val == target) return {l+1, r + 1};
		else if (val < target) ++l;
		else --r;
	}
	return {};
}
