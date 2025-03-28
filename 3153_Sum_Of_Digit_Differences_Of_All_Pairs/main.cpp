#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {13, 23, 12};
	Solution *test = new Solution();
	cout << test->sumDigitDifferences(input) << endl;
	return 0;
}
