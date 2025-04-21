#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-40};
	int lower = -46;
	int upper = 53;
	Solution *test = new Solution();
	cout << test->numberOfArrays(input, lower, upper) << endl;
	return 0;
}
