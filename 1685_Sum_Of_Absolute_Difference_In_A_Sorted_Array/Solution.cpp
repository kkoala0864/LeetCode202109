#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

vector<int> Solution::getSumAbsoluteDifferences(vector<int>& nums) {
	vector<int> diff(1, 0);
	vector<int> preDiff(1, 0);
	int sum = 0;
	int size = nums.size();
	for (int i = 1 ; i < nums.size() ; ++i) {
		diff.emplace_back(nums[i] - nums[0]);
		sum += diff.back();
		preDiff.emplace_back(preDiff.back() + diff.back());
	}
	vector<int> result;
	result.emplace_back(sum);

	for (int i = 1 ; i < nums.size() ; ++i) {
		sum = result[0];
		int pre = abs(preDiff[i-1] - (diff[i] * i));
		int post = (diff[i] * (size - i));
		sum = sum - preDiff[i-1] + pre - post;
		result.emplace_back(sum);
	}
	return result;
}
