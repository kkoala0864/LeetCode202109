#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "qlkzenwmmnpkopu";
	int k = 15;
	Solution *test = new Solution();
	cout << test->canConstruct(input, k) << endl;
	return 0;
}
