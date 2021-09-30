#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {9,6,4,2,3,5,7,0,1};
	Solution* test = new Solution();
	cout << test->missingNumber(input) << endl;
	return 0;
}

