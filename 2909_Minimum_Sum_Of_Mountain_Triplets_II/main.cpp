#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {6, 5, 4, 3, 4, 5};
	Solution *test = new Solution();
	cout << test->minimumSum(input) << endl;
	return 0;
}
