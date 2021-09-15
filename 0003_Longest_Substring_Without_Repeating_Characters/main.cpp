#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = string(" ");

	Solution* test = new Solution();
	cout << test->lengthOfLongestSubstring(input) << endl;
	return 0;
}

