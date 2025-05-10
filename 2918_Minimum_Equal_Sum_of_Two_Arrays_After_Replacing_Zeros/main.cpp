#include <Solution.h>

int main(void) {
	vector<int> nums1 = {2,0,2,0};
	vector<int> nums2 = {1,4};
	Solution *test = new Solution();
	cout << test->minSum(nums1, nums2) << endl;
	return 0;
}
