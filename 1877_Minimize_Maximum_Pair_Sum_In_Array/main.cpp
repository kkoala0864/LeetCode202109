#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 5, 4, 2, 4, 6};
	Solution *test = new Solution();
	cout << test->minPairSum(input) << endl;
	return 0;
}
