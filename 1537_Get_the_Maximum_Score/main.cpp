#include <Solution.h>

int main(void) {
	vector<int> nums1 = {2,4,5,8,10};
	vector<int> nums2 = {4,6,8,9};
	Solution *test = new Solution();
	cout << test->maxSum(nums1, nums2) << endl;
	return 0;
}
