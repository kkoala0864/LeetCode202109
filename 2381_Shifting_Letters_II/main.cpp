#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "abc";
	vector<vector<int>> shifts = {{0,1,0},{1,2,1},{0,2,1}};
	Solution* test = new Solution();
	cout << test->shiftingLetters(input, shifts) << endl;
	return 0;
}

