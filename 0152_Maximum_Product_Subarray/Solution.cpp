#include <Solution.h>
#include <iostream>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;

int Solution::maxProduct(vector<int>& nums) {
	int maxVal = INT_MIN;
	int product = 1;
	int lastZero = -1;
	for (int i = 0 ; i < nums.size() ; ++i) {
		if (nums[i] != 0) {
			product *= nums[i];
			maxVal = max(product, maxVal);
		} else {
			maxVal = max(0, maxVal);
			if (product < 0) {
				for (int j = lastZero + 1 ; j < (i-1) ; ++j) {
					product /= nums[j];
					maxVal = max(maxVal, product);
				}
			}
			product = 1;
			lastZero = i;
		}
	}

	if (product < 0) {
		for (int j = lastZero + 1; j < nums.size()-1 ; ++j) {
			product /= nums[j];
			maxVal = max(maxVal, product);
		}
	}
	return maxVal;
}
