#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,5,3,4};
	Solution* test = new Solution();
	cout << test->numRescueBoats(input, 5) << endl;
	return 0;
}

