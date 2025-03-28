#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> input = {{'W', 'W', 'B'}, {'W', 'B', 'W'}, {'B', 'W', 'W'}};
	Solution *test = new Solution();
	cout << test->findLonelyPixel(input) << endl;
	return 0;
}
