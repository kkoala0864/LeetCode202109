#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-7,-8,7,5,7,1,6,0};
	Solution* test = new Solution();
	auto result = test->maxSlidingWindow(input, 4);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	result = test->dp(input, 4);
	for (const auto& val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

