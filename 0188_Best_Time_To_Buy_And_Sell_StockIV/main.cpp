#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> prices = {2,4,1};
	Solution* test = new Solution();
	cout << test->maxProfit(2, prices) << endl;
	return 0;
}

