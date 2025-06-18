#include <Solution.h>

// the value is vector is in order or out of order
// what's the length range of the vector
// we can sort the vector and get each k value in order to form the vector
// every time we get eack k value we need to check the first value and kth value differen is small or equal than k
vector<vector<int>> Solution::divideArray(vector<int> &nums, int k) {
	vector<vector<int>> result;
	if (nums.size() % 3) return result;

	sort(nums.begin(), nums.end());
	for (int i = 0 ; i < nums.size() ; i += 3) {
		if ((nums[i + 2] - nums[i]) > k) return {};
		result.push_back({nums[i], nums[i+1], nums[i+2]});
	}
	return result;
}
// TC : O(nlogn)
// SC : O(n);
