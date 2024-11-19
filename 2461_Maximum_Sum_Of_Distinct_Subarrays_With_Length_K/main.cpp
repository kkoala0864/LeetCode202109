#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,5,4,2,9,9,9};
	int k = 3;
	Solution* test = new Solution();
	cout << test->maximumSubarraySum(input, k) << endl;
	return 0;
}

