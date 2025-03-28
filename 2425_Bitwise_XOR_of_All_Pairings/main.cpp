#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {2, 1, 3};
	vector<int> input2 = {10, 2, 5, 0};
	Solution *test = new Solution();
	cout << test->xorAllNums(input1, input2) << endl;
	return 0;
}
