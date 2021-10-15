#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "ab";
	Solution* test = new Solution();
	cout << test->lengthOfLongestSubstringKDistinct(input, 1) << endl;
	return 0;
}

