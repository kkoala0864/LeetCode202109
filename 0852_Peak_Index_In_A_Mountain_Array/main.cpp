#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,10, 5, 2};
	Solution* test = new Solution();
	cout << test->peakIndexInMountainArray(input) << endl;
	return 0;
}

