#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "leetcode";
	string s2 = "practice";
	Solution* test = new Solution();
	cout << test->minSteps(s1, s2) << endl;
	return 0;
}

