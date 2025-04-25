#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> gas = {1, 2, 3, 4, 5};
	vector<int> cost = {3, 4, 5, 1, 2};
	Solution *test = new Solution();
	cout << test->canCompleteCircuit(gas, cost) << endl;
	cout << test->canCompleteCircuit2(gas, cost) << endl;
	cout << test->canCompleteCircuit3(gas, cost) << endl;
	return 0;
}
