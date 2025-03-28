#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {60, 60, 60};
	Solution *test = new Solution();
	cout << test->numPairsDivisibleBy60(input) << endl;
	return 0;
}
