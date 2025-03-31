#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "abcdefg";
	string s2 = "bcdffg";
	Solution *test = new Solution();
	cout << test->minStartingIndex(s1, s2) << endl;
	return 0;
}
