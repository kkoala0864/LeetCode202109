#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "aabcb";
	Solution *test = new Solution();
	cout << test->beautySum(s) << endl;
	return 0;
}
