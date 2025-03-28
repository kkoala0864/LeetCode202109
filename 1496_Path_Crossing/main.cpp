#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "NESWW";
	Solution *test = new Solution();
	cout << test->isPathCrossing(input) << endl;
	return 0;
}
