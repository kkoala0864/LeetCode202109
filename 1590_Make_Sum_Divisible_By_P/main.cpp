#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {14,22,14,12,1,20,8,21,20,7,12,14,24,12};
	int p = 2;
	Solution* test = new Solution();
	cout << test->minSubarray(input, p) << endl;
	return 0;
}

