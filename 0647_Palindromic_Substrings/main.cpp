#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("aaa");
	Solution *test = new Solution();
	cout << test->countSubstrings(input) << endl;
	return 0;
}
