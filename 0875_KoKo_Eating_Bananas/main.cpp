#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,1,1,999999999};
	Solution* test = new Solution();
	cout << test->minEatingSpeed(input, 10) << endl;
	cout << test->minEatingSpeed2(input, 10) << endl;
	return 0;
}

