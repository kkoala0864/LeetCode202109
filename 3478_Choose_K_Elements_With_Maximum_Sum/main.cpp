#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums1 = {4,2,1,5,3};
	vector<int> nums2 = {10,20,30,40,50};
	int k = 2;
	Solution* test = new Solution();
	auto result = test->findMaxSum(nums1, nums2, k);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

