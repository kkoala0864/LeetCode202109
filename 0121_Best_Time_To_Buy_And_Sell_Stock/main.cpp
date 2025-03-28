#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {7, 1, 5, 3, 6, 4};
	Solution *test = new Solution();
	cout << test->maxProfit(input) << endl;
	cout << test->maxProfit2(input) << endl;
	cout << test->maxProfit3(input) << endl;
	return 0;
}
