#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> push = {1,2,3,4,5};
	vector<int> pop = {4,3,5,1,2};
	Solution* test = new Solution();
	cout << test->validateStackSequences(push, pop) << endl;
	return 0;
}

