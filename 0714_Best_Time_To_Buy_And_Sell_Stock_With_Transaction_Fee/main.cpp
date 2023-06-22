#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> prices = {1,3,7,5,10,3};
	int fee = 3;
	Solution* test = new Solution();
	cout << test->maxProfit(prices, fee) << endl;
	return 0;
}

