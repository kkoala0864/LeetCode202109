#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> prices = {1,3,2,8,4,9};
	int fee = 2;
	Solution* test = new Solution();
	cout << test->maxProfit(prices, fee) << endl;
	cout << test->maxProfit2(prices, fee) << endl;
	return 0;
}

