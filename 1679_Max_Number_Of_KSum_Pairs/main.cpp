#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,1,3,4,3};
	Solution* test = new Solution();
	cout << test->maxOperations(input, 6) << endl;
	return 0;
}

