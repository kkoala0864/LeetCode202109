#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {2,1,5,6,2,3};
	Solution* test = new Solution();
	cout << test->largestRectangleArea(input) << endl;
	return 0;
}

