#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,7,11,15};
	Solution* test = new Solution();
	auto result = test->twoSum(input, 9);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

