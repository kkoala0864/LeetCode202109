#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.");
	Solution* test = new Solution();
	cout << test->countValidWords(input) << endl;
	cout << test->countValidWords2(input) << endl;
	return 0;
}

