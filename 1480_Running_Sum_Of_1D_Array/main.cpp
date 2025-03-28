#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 4};
	Solution *test = new Solution();
	auto result = test->runningSum(input);
	for (const auto &val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
