#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10, 4, -8, 7};
	Solution *test = new Solution();
	cout << test->waysToSplitArray(input) << endl;
	return 0;
}
