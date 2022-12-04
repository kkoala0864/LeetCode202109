#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,5,3,9,5,3};
	Solution* test = new Solution();
	cout << test->minimumAverageDifference(input) << endl;
	return 0;
}

