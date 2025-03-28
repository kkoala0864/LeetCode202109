#include <Solution.h>
#include <iostream>
//[1, 2, 3, 4]
//
// from
//[1, 2, 6]
// back
//[4, 12, 24]
//
// nums
//[24, from[0] * back[1], from[1] * back[0], 6]
// a b c d
// 1 a ab abc
//
vector<int> Solution::productExceptSelf2(vector<int> &nums) {
	vector<int> prefixProduct(1, 1);
	int product = 1;
	for (int i = 0; i < nums.size() - 1; ++i) {
		product *= nums[i];
		prefixProduct.emplace_back(product);
	}
	product = 1;
	for (int i = nums.size() - 1; i > 0; --i) {
		product *= nums[i];
		prefixProduct[i - 1] *= product;
	}
	return prefixProduct;
}
