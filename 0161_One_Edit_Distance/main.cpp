#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("ab");
	string t("acb");
	Solution* test = new Solution();
	cout << test->isOneEditDistance(s, t) << endl;
	return 0;
}

