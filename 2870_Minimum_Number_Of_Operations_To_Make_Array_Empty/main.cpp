#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,3,3,2,2,4,2,3,4};
	Solution* test = new Solution();
	cout << test->minOperations(input) << endl;
	return 0;
}

