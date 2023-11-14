#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabca";
	Solution* test = new Solution();
	cout << test->countPalindromicSubsequence(input) << endl;
	return 0;
}

