#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,1,0,4};
	Solution* test = new Solution();
	cout << test->canJump(input) << endl;
	return 0;
}

