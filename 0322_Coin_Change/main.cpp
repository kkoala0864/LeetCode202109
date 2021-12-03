#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {125,146,125,252,226,25,24,308,50};
	Solution* test = new Solution();
	cout << test->coinChange(input, 8402) << endl;
	cout << test->coinChange2(input, 3) << endl;
	return 0;
}
