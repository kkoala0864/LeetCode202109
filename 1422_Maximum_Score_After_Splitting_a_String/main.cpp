#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "011101";
	Solution *test = new Solution();
	cout << test->maxScore(input) << endl;
	return 0;
}
