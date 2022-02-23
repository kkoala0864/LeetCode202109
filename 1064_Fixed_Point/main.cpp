#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-10,-5,-2,0,4,5,6,7,8,9,10};
	Solution* test = new Solution();
	cout << test->fixedPoint(input) << endl;
	return 0;
}

