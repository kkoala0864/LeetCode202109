#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabccabba";
	Solution *test = new Solution();
	cout << test->minimumLength(input) << endl;
	return 0;
}
