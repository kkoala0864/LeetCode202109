#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> horizontalCut = {1,3};
	vector<int> verticalCut = {5};
	Solution* test = new Solution();
	cout << test->minimumCost(3, 2, horizontalCut, verticalCut) << endl;
	return 0;
}

