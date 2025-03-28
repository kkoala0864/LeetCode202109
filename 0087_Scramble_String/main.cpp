#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s1 = "abcdefghijklmn";
	string s2 = "efghijklmncadb";
	Solution *test = new Solution();
	cout << test->isScramble(s1, s2) << endl;
	return 0;
}
