#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	cout << test->removePalindromeSub("ababa") << endl;
	return 0;
}
