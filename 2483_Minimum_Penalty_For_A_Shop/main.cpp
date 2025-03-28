#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "YYYY";
	Solution *test = new Solution();
	cout << test->bestClosingTime(input) << endl;
	return 0;
}
