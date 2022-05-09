#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "2222";
	Solution* test = new Solution();
	cout << test->countTexts(input) << endl;
	return 0;
}

