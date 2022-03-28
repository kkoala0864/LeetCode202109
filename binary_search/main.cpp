#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,3,5,7,9,11,13,17,19};
	Solution* test = new Solution();
	cout << test->general(input, 3) << endl;
	cout << test->general(input, 1) << endl;
	cout << test->general(input, 8) << endl;
	cout << test->findFirstBiggerThanMe(input, 12) << endl;
	cout << test->findFirstBiggerThanMe(input, 18) << endl;
	cout << test->findFirstBiggerThanMe(input, 0) << endl;
	cout << test->findMinimalValInRotatedArray(input) << endl;
	return 0;
}

