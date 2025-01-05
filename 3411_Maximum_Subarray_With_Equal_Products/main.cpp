#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,1,4,5,1};
	Solution* test = new Solution();
	cout << test->maxLength(input) << endl;
	return 0;
}

