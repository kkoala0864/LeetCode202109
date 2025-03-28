#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input1 = "abcde";
	string input2 = "ace";
	Solution *test = new Solution();
	cout << test->longestCommonSubsequence(input1, input2) << endl;
	cout << test->longestCommonSubsequence2(input1, input2) << endl;
	return 0;
}
