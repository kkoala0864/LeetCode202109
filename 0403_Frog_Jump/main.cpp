#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,1,2,3,4,8,9,11};
	Solution* test = new Solution();
	cout << test->canCross(input) << endl;
	return 0;
}

