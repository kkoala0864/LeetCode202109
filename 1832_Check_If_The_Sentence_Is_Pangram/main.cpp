#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "thequickbrownfoxjumpsoverthelazydog";
	Solution* test = new Solution();
	cout << test->checkIfPangram(input) << endl;
	return 0;
}

