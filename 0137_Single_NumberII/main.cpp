#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {-3, -3, -2, -3};
	Solution* test = new Solution();
	cout << test->singleNumber(input) << endl;
	cout << test->singleNumber2(input) << endl;
	return 0;
}

