#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "foo";
	string input2 = "abc";
	Solution* test = new Solution();
	cout << test->isIsomorphic(input1, input2) << endl;
	cout << test->isIsomorphic2(input1, input2) << endl;
	return 0;
}

