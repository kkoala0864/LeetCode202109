#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabcaabdaab";
	Solution* test = new Solution();
	cout << test->longestRepeatingSubstring(input) << endl;
	return 0;
}

