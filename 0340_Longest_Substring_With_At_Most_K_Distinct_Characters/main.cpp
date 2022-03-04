#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "eceba";
	Solution* test = new Solution();
	cout << test->lengthOfLongestSubstringKDistinct(input, 2) << endl;
	cout << test->lengthOfLongestSubstringKDistinct2(input, 2) << endl;
	return 0;
}

