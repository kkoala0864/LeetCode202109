#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 4, 3, 3, 2};
	Solution *test = new Solution();
	cout << test->longestMonotonicSubarray(input) << endl;
	return 0;
}
