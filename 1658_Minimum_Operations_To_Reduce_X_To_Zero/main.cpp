#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,20,1,1,3};
	Solution* test = new Solution();
	cout << test->minOperations(input, 10) << endl;
	return 0;
}

