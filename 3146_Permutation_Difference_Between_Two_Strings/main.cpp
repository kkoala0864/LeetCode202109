#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "abc";
	string s2 = "bac";
	Solution *test = new Solution();
	cout << test->findPermutationDifference(s1, s2) << endl;
	return 0;
}
