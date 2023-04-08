#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,7,1,6};
	Solution* test = new Solution();
	cout << test->minimizeArrayValue(input) << endl;
	return 0;
}

