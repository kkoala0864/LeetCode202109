#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10, 2, -10, 5, 20};
	Solution *test = new Solution();
	cout << test->constrainedSubsetSum(input, 2) << endl;
	return 0;
}
