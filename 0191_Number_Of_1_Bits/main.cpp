#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	uint32_t input = 11;
	Solution *test = new Solution();
	cout << test->hammingWeight(input) << endl;
	cout << test->hammingWeight2(input) << endl;
	cout << test->hammingWeight3(input) << endl;
	return 0;
}
