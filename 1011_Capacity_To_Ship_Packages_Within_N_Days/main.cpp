#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,2,3,4,5,6,7,8,9,10};
	Solution* test = new Solution();
	cout << test->shipWithinDays(input, 5) << endl;
	return 0;
}

