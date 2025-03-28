#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "cba";
	Solution *test = new Solution();
	cout << test->orderlyQueue(input, 1) << endl;
	return 0;
}
