#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "abcd";
	int k = 2;
	Solution *test = new Solution();
	cout << test->stringHash(s, k) << endl;
	return 0;
}
