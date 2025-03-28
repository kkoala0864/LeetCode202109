#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abciiidef";
	Solution *test = new Solution();
	cout << test->maxVowels(input, 3) << endl;
	return 0;
}
