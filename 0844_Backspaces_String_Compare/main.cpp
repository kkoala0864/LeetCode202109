#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("ab#c");
	string t("ad#c");
	Solution* test = new Solution();
	cout << test->backspaceCompare(s, t) << endl;
	cout << test->backspaceCompare2(s, t) << endl;
	return 0;
}

