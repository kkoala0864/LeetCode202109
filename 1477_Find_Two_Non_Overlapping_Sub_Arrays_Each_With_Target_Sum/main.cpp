#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,6,1};
	int target = 7;
	Solution* test = new Solution();
	cout << test->minSumOfLengths(input, target) << endl;
	return 0;
}

