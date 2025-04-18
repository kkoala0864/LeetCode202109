#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	Solution *test = new Solution();
	int input = 4;
	cout << test->countAndSay(input) << endl;
	return 0;
}
