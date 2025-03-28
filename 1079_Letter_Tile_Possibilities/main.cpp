#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "AAB";
	Solution *test = new Solution();
	cout << test->numTilePossibilities(input) << endl;
	return 0;
}
