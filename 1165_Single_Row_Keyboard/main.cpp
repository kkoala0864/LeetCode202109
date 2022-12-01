#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abcdefghijklmnopqrstuvwxyz";
	string keyword = "cba";
	Solution* test = new Solution();
	cout << test->calculateTime(input, keyword) << endl;
	return 0;
}

