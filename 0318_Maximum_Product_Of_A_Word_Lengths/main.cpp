#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
	Solution *test = new Solution();
	cout << test->maxProduct(input) << endl;
	cout << test->maxProduct2(input) << endl;
	cout << test->maxProduct3(input) << endl;
	return 0;
}
