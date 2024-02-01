#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "abc";
	string input2 = "pqr";
	Solution* test = new Solution();
	cout << test->mergeAlternately(input1, input2) << endl;
	return 0;
}

