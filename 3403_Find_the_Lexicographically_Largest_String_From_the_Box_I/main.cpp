#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "dbca";
	int num = 2;
	Solution *test = new Solution();
	cout << test->answerString(input, num) << endl;
	return 0;
}
