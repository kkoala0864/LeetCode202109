#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aaaaaaaaaaaaaabb";
	Solution* test = new Solution();
	cout << test->compressedString(input) << endl;
	return 0;
}

