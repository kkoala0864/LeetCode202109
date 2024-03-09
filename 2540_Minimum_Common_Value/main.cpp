#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1,2,3}, input2 = {2,4};
	Solution* test = new Solution();
	cout << test->getCommon(input1, input2) << endl;
	return 0;
}

