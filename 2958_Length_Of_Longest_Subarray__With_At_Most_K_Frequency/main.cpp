#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 1, 2, 3, 1, 2};
	int k = 2;
	Solution *test = new Solution();
	cout << test->maxSubarrayLength(input, k) << endl;
	return 0;
}
