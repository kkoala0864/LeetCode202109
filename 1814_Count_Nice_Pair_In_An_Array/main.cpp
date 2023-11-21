#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {13,10,35,24,76};
	Solution* test = new Solution();
	cout << test->countNicePairs(input) << endl;
	return 0;
}

