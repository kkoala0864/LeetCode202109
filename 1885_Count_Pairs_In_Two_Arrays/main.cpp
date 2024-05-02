#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums1 = {1, 10, 6, 2};
	vector<int> nums2 = {1, 4, 1, 5};
	Solution* test = new Solution();
	cout << test->countPairs(nums1, nums2) << endl;
	return 0;
}

