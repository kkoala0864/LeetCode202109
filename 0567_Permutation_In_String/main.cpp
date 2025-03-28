#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1("ab");
	string s2("eidbaooo");
	Solution *test = new Solution();
	cout << test->checkInclusion(s1, s2) << endl;
	cout << test->checkInclusion2(s1, s2) << endl;
	return 0;
}
