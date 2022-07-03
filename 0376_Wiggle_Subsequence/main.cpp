#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,0,0};
	Solution* test = new Solution();
	cout << test->wiggleMaxLength(input) << endl;
	cout << test->wiggleMaxLength2(input) << endl;
	cout << test->wiggleMaxLength3(input) << endl;
	return 0;
}

