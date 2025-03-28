#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9, 48, 92, 48, 81, 31};
	Solution *test = new Solution();
	cout << test->minDifference(input) << endl;
	return 0;
}
