#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {60, 60, 60};
	vector<int> input2 = {10, 90, 10};

	Solution* test = new Solution();
	cout << test->maximumsSplicedArray(input1, input2) << endl;
	return 0;
}

