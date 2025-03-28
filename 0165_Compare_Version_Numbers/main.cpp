#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "1.0";
	string s2 = "1.0.0";
	Solution *test = new Solution();
	cout << test->compareVersion(s1, s2) << endl;
	cout << test->compareVersion2(s1, s2) << endl;
	return 0;
}
