#include <Solution.h>

int main(void) {
	vector<int> nums1 = {1,2,1,3,2};
	vector<int> nums2 = {5,3,4,6,2};
	Solution *test = new Solution();
	cout << test->maxSumDistinctTriplet(nums1, nums2) << endl;
	return 0;
}
