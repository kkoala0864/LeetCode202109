#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s("a good   example");
	Solution* test = new Solution();
	cout << test->reverseWords(s) << endl;
	return 0;
}
