#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums1 = {1,2,3,2,1}, nums2 = {3,2,1,4,7};
	Solution* test = new Solution();
	cout << test->findLength(nums1, nums2) << endl;
	return 0;
}

