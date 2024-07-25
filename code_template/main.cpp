#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {5,1,1,2,0,0};
	Solution* test = new Solution();
	auto result = test->quick_sort(nums);
	for (const auto& v : result) cout << v << " ";
	cout << endl;

	nums = {3, 9, 19, 5, 6, 7, 8};
	for (const auto& v : nums) cout << v << " ";
	cout << endl;
	cout << test->quick_select(nums, 3) << endl;

	return 0;
}

