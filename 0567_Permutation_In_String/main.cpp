#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1("hello");
	string s2("ooolleoooleh");
	Solution* test = new Solution();
	cout << test->checkInclusion(s1, s2) << endl;
	cout << test->checkInclusion2(s1, s2) << endl;
	return 0;
}

