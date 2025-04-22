#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<char>> image = {{'0','0','1','0'},{'0','1','1','0'},{'0','1','0','0'}};
	int x = 0;
	int y = 2;
	Solution *test = new Solution();
	cout << test->minArea(image, x, y) << endl;
	return 0;
}
