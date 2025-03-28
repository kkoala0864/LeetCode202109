#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3, 9, 7, 3};
	Solution *test = new Solution();
	cout << test->minimumDifference(input) << endl;
	return 0;
}
