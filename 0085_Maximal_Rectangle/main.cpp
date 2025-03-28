#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'1', '0'}};
	Solution *test = new Solution();
	cout << test->maximalRectangle(input) << endl;
	return 0;
}
