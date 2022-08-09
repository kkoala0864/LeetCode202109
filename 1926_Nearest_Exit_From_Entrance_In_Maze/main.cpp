#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'.','+','+','+'},{'+','+','+','+'},{'+','+','+','.'},{'+','.','.','+'}};
	vector<int> entrance = {0, 0};
	Solution* test = new Solution();
	cout << test->nearestExit(input, entrance) << endl;
	return 0;
}

