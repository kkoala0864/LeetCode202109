#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,1,5};
	Solution* test = new Solution();
	cout << test->countMaxOrSubsets(input) << endl;
	return 0;
}

