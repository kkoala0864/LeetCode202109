#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {6,0,8,2,1,5};
	Solution* test = new Solution();
	cout << test->maxWidthRamp(input) << endl;
	return 0;
}

