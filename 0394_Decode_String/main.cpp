#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "2[abc]3[cd]ef";
	Solution *test = new Solution();
	cout << test->decodeString(input) << endl;
	return 0;
}
