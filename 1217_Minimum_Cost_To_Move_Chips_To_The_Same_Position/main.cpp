#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {6,4,7,8,2,10,2,7,9,7};
	Solution* test = new Solution();
	cout << test->minCostToMoveChips(input) << endl;
	return 0;
}

