#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-14, -13, -20};
	Solution *test = new Solution();
	cout << test->maximumTotalCost(input) << endl;
	return 0;
}
