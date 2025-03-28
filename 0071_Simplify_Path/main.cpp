#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "/a//b////c/d//././/..";
	Solution *test = new Solution();
	cout << test->simplifyPath(input) << endl;
	cout << test->simplifyPath2(input) << endl;
	return 0;
}
