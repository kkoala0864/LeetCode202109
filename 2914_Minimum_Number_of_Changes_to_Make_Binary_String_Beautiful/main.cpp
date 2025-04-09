#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "1001";
	Solution *test = new Solution();
	cout << test->minChanges(s) << endl;
	return 0;
}
