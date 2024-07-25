#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> nums = {5,1,1,2,0,0};
	Solution* test = new Solution();
	auto result = test->Quick_Sort(nums);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

