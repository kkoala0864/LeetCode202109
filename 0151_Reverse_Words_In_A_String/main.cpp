#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("  hello world  ");
	Solution *test = new Solution();
	cout << test->reverseWords(s) << endl;
	cout << test->reverseWords2(s) << endl;
	return 0;
}
