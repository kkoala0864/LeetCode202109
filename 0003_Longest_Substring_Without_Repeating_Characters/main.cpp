#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = string("abcabcbb");

	Solution *test = new Solution();
	cout << test->lengthOfLongestSubstring(input) << endl;
	cout << test->lengthOfLongestSubstring2(input) << endl;
	cout << test->lengthOfLongestSubstring4(input) << endl;
	return 0;
}
