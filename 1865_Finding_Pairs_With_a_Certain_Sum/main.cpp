#include <Solution.h>

int main(void) {
	//["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
	//[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
	vector<int> nums1 = {1, 1, 2, 2, 2, 3};
	vector<int> nums2 = {1, 4, 5, 2, 5, 4};
	FindSumPairs* test = new FindSumPairs(nums1, nums2);
	cout << test->count(7) << endl;
	test->add(3, 2);
	cout << test->count(8) << endl;
	cout << test->count(4) << endl;
	test->add(0, 1);
	test->add(1, 1);
	cout << test->count(7) << endl;
	return 0;
}
