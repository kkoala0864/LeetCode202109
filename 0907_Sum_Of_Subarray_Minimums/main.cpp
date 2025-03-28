#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 1, 2, 4};
	Solution *test = new Solution();
	cout << test->sumSubarrayMins(input) << endl;
	return 0;
}
