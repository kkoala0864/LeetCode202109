#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input1 = {1, 2, 4}, input2 = {1, 4 ,2};
	Solution* test = new Solution();
	cout << test->maxUncrossedLines(input1, input2) << endl;
	return 0;
}

