#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-9, 1, 3, -11, 2, -3, 1};
	Solution *test = new Solution();
	cout << test->maxSumAfterOperation(input) << endl;
	return 0;
}
