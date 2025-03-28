#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("aaaa");
	string t("bbaa");
	Solution *test = new Solution();
	cout << test->isSubsequence(s, t) << endl;
	cout << test->isSubsequence2(s, t) << endl;
	return 0;
}
