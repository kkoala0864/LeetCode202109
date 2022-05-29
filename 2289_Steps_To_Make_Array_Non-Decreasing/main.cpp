#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10,1,2,3,4,5,6,1,2,3};
	Solution* test = new Solution();
	cout << test->totalSteps(input) << endl;
	return 0;
}

