#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,6,4,1,2};
	int target = 3;
	Solution* test = new Solution();
	cout << test->maximumJumps(input, target) << endl;
	return 0;
}

