#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->lengthOfLongestSubstringTwoDistinct("eceba") << endl;
	return 0;
}
