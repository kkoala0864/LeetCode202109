#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,4,3,0,4};
	Solution* test = new Solution();
	cout << test->specialArray(input) << endl;
	return 0;
}

