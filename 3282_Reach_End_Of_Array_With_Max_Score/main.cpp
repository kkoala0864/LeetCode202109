#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,1,5};
	Solution* test = new Solution();
	cout << test->findMaximumScore(input) << endl;
	return 0;
}

