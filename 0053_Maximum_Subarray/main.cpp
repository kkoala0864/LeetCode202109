#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
	Solution* test = new Solution();
	cout << test->maxSubArray(input) << endl;
	cout << test->maxSubArray2(input) << endl;
	return 0;
}

