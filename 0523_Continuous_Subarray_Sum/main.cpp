#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {23,2,4,6,7};
	Solution* test = new Solution();
	cout << test->checkSubarraySum(input, 6) << endl;
	return 0;
}

