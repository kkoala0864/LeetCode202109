#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abBAcC";
	Solution *test = new Solution();
	cout << test->makeGood(input) << endl;
	return 0;
}
