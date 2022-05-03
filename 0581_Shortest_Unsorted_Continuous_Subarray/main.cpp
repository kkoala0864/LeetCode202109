#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,6,4,8,10,9,15};
	Solution* test = new Solution();
	cout << test->findUnsortedSubarray(input) << endl;
	return 0;
}

