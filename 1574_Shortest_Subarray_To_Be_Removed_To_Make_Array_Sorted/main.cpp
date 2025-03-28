#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 2, 2, 2, 2, 3, 1, 7, 5, 1, 2, 2, 2, 2, 2, 2, 5, 6};
	Solution *test = new Solution();
	cout << test->findLengthOfShortestSubarray(input) << endl;
	return 0;
}
