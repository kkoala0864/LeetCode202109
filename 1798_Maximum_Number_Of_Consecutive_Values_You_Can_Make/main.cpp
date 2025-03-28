#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 1, 3, 3, 10};
	Solution *test = new Solution();
	cout << test->getMaximumConsecutive(input) << endl;
	return 0;
}
