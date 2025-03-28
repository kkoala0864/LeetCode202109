#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("teacher");
	string t("detacher");
	Solution *test = new Solution();
	cout << test->isOneEditDistance(s, t) << endl;
	cout << test->isOneEditDistance2(s, t) << endl;
	return 0;
}
