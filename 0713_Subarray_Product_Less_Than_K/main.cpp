#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10,5,2,6};
	Solution* test = new Solution();
	cout << test->numSubarrayProductLessThanK(input, 100) << endl;
	return 0;
}

