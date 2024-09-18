#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {3,30,34,5,9};
	Solution* test = new Solution();
	cout << test->largestNumber(input) << endl;
	cout << test->largestNumber2(input) << endl;
	return 0;
}

