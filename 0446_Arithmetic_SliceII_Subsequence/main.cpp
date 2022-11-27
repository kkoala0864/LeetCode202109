#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,4,6,8,10};
	Solution* test = new Solution();
	cout << test->numberOfArithmeticSlices(input) << endl;
	cout << test->Standard(input) << endl;
	return 0;
}

