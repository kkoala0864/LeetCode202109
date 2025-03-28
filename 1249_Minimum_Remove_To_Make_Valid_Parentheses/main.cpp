#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("lee(t(c)o)de)");
	Solution *test = new Solution();
	cout << test->minRemoveToMakeValid(input) << endl;
	return 0;
}
