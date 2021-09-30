#include <Solution.h>
#include <iostream>
//[1, 2, 3, 4]
//
//from
//[1, 2, 6]
//back
//[4, 12, 24]
//
//nums
//[24, from[0] * back[1], from[1] * back[0], 6]
/*
vector<int> Solution::productExceptSelf(vector<int>& nums) {
	int size = nums.size();
	vector<int> from(size-1,1), back(size-1,1);

	from[0] = nums[0];
	back[0] = nums[size-1];
	for (int i = 1 ; i < (size-1) ; ++i) {
		from[i] = from[i-1] * nums[i];
		back[i] = back[i-1] * nums[size-i-1];
	}

	nums[0] = back[size-2];
	nums[size-1] = from[size-2];
	for (int i = 1 ; i < (size-1) ; ++i) {
		nums[i] = from[i-1] * back[size-i-2];
	}
	return nums;
}
*/
vector<int> Solution::productExceptSelf(vector<int>& nums) {
	int size = nums.size();
	vector<int> result(1, 1);

	int product = 1;
	for (int i = 0 ; i < size-1 ; ++i) {
		product *= nums[i];
		result.emplace_back(product);
	}
	product = nums[size-1];
	for (int i = size - 2 ; i >= 0 ; --i) {
		result[i] = result[i] * product;
		product *= nums[i];
	}
	return result;
}
