#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10, 1, 10, 9, 6, 1, 9, 5, 9, 10, 7, 8, 5, 2, 10, 8};
	Solution *test = new Solution();
	cout << test->canPartitionKSubsets(input, 11) << endl;
	cout << test->canPartitionKSubsets2(input, 11) << endl;
	return 0;
}
