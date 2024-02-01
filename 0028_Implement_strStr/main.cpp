#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "leetcode";
	string needle = "leeto";
	Solution* test = new Solution();
	cout << test->strStr(input, needle) << endl;
	cout << test->strStr2(input, needle) << endl;
	cout << test->strStr3(input, needle) << endl;
	return 0;
}

