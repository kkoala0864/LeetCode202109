#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "1010101";
	int k = 2;
	Solution* test = new Solution();
	cout << test->countKConstraintSubstrings(input, k) << endl;
	return 0;
}

