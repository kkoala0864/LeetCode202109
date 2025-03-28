#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "delete", s2 = "leet";
	Solution *test = new Solution();
	cout << test->minimumDeleteSum(s1, s2) << endl;
	return 0;
}
