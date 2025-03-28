#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> prices = {3, 2, 6, 5, 0, 3};
	Solution *test = new Solution();
	cout << test->maxProfit(2, prices) << endl;
	cout << test->maxProfit3(2, prices) << endl;
	return 0;
}
