#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abc";
	vector<vector<int>> shift = {{0, 1}, {1, 2}};
	Solution *test = new Solution();
	cout << test->stringShift(input, shift) << endl;
	return 0;
}
