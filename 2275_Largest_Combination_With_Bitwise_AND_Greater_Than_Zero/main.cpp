#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {16, 17, 71, 62, 12, 24, 14};
	Solution *test = new Solution();
	cout << test->largestCombination(input) << endl;
	return 0;
}
