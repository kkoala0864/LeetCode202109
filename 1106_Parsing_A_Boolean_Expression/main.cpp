#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "!(&(f,t))";
	Solution *test = new Solution();
	cout << test->parseBoolExpr(s) << endl;
	return 0;
}
