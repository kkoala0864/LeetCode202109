#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "TTFF";
	int k = 2;
	Solution *test = new Solution();
	cout << test->maxConsecutiveAnswers(input, k) << endl;
	return 0;
}
