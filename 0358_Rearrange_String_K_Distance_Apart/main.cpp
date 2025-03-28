#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aaadbbcc";
	Solution *test = new Solution();
	cout << test->rearrangeString(input, 2) << endl;
	return 0;
}
