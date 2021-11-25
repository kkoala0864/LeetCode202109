#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "/a/./b/../../c/";
	Solution* test = new Solution();
	cout << test->simplifyPath(input) << endl;
	return 0;
}

