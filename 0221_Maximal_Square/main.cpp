#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'1', '0', '1', '0'}, {'1', '0', '1', '1'}, {'1', '0', '1', '1'}, {'1', '1', '1', '1'}};
	Solution *test = new Solution();
	cout << test->maximalSquare(input) << endl;
	cout << test->maximalSquare2(input) << endl;
	return 0;
}
