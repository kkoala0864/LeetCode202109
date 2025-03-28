#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 5};
	Solution *test = new Solution();
	cout << test->coinChange(input, 11) << endl;
	cout << test->coinChange2(input, 11) << endl;
	cout << test->coinChange3(input, 11) << endl;
	cout << test->coinChange4(input, 11) << endl;
	return 0;
}
