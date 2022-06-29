#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1,2,3};
	vector<int> input2 = {1,2,3,4};
	Solution* test = new Solution();
	cout << test->maxBoxesInWarehouse(input1, input2) << endl;
	return 0;
}

