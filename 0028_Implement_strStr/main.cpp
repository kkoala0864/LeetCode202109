#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "leetcode";
	string needle = "leeto";
	Solution *test = new Solution();
	cout << test->strStr(input, needle) << endl;
	return 0;
}
