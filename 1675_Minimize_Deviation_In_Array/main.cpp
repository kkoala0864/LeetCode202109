#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9,4,3,6,2};
	Solution* test = new Solution();
	cout << test->minimumDeviation(input) << endl;
	return 0;
}

