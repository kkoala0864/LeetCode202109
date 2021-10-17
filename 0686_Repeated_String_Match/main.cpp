#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("abcd");
	string t("cdabcdab");
	Solution* test = new Solution();
	cout << test->repeatedStringMatch(s, t) << endl;
	return 0;
}

