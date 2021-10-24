#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input("cat and  dog");
	Solution* test = new Solution();
	cout << test->countValidWords(input) << endl;
	return 0;
}

