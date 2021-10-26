#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10, 2};
	Solution* test = new Solution();
	cout << test->largestNumber(input) << endl;
	return 0;
}

