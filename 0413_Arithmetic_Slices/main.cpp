#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4};
	Solution* test = new Solution();
	cout << test->numberOfArithmeticSlices(input) << endl;
	return 0;
}

