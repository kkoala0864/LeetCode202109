#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "ipkfbwas";
	int k = 13;
	Solution *test = new Solution();
	cout << test->longestPalindromicSubsequence(input, k) << endl;
	return 0;
}
