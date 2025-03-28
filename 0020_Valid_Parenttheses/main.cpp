#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("()[]{}");
	Solution *test = new Solution();
	cout << test->isValid(input) << endl;
	cout << test->isValid2(input) << endl;
	cout << test->isValid3(input) << endl;
	return 0;
}
