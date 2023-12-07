#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "ihroyeeb";
	Solution* test = new Solution();
	cout << test->beautifulSubstrings(input, 5) << endl;
	return 0;
}

