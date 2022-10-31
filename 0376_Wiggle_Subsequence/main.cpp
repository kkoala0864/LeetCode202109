#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1,17,5,10,13,15,10,5,16,8};
	Solution* test = new Solution();
	cout << test->wiggleMaxLength(input) << endl;
	cout << test->wiggleMaxLength2(input) << endl;
	cout << test->wiggleMaxLength3(input) << endl;
	cout << test->wiggleMaxLength4(input) << endl;
	return 0;
}

