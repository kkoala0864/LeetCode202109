#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4,5};
	Solution* test = new Solution();
	cout << test->countPairs(input, 2) << endl;
	return 0;
}

