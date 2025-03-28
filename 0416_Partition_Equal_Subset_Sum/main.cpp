#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 5};
	Solution *test = new Solution();
	cout << test->canPartition(input) << endl;
	cout << test->canPartition2(input) << endl;
	return 0;
}
