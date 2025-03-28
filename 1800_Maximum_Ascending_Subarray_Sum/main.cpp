#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {10, 20, 30, 5, 10, 50};
	Solution *test = new Solution();
	cout << test->maxAscendingSum(input) << endl;
	return 0;
}
