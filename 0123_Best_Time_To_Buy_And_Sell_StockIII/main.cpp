#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,3,5,0,0,3,1,4};
	Solution* test = new Solution();
	cout << test->maxProfit(input) << endl;
	cout << test->maxProfit2(input) << endl;
	return 0;
}

