#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,2,3,2,2,2};
	Solution* test = new Solution();
	cout << test->divideArray(input) << endl;
	return 0;
}

