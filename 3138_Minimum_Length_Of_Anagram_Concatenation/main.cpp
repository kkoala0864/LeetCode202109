#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abba";
	Solution *test = new Solution();
	cout << test->minAnagramLength(input) << endl;
	return 0;
}
