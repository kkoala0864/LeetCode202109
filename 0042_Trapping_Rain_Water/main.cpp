#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {4,2,0,3,2,5};
	Solution* test = new Solution();
	cout << test->trap(input) << endl;
	return 0;
}

