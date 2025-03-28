#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "leetcode";
	int k = 2;
	Solution *test = new Solution();
	cout << test->getLucky(input, k) << endl;
	return 0;
}
