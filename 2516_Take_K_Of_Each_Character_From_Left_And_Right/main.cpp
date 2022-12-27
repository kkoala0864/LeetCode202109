#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "aabaaaacaabc";
	Solution* test = new Solution();
	cout << test->takeCharacters(input, 2) << endl;
	return 0;
}

