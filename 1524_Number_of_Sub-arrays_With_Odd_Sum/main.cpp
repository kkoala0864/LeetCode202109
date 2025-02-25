#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,5};
	Solution* test = new Solution();
	cout << test->numOfSubarrays(input) << endl;
	return 0;
}

