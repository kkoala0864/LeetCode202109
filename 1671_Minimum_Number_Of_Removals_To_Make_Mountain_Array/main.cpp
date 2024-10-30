#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {100,92,89,77,74,66,64,66,64};
	Solution* test = new Solution();
	cout << test->minimumMountainRemovals(input) << endl;
	return 0;
}

