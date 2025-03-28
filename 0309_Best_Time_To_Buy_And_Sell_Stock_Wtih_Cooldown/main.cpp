#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 2, 3, 0, 2};
	Solution *test = new Solution();
	cout << test->maxProfit(input) << endl;
	cout << test->maxProfit2(input) << endl;
	return 0;
}
