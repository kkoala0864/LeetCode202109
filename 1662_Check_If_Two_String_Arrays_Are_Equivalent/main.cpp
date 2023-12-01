#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input1 = {"a", "cb"};
	vector<string> input2 = {"ab", "c"};
	Solution* test = new Solution();
	cout << test->arrayStringsAreEqual(input1, input2) << endl;
	return 0;
}

