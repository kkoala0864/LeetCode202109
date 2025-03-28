#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 0, 0, 0, 0}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 0}};
	vector<int> ball = {4, 3};
	vector<int> hole = {3, 0};
	Solution *test = new Solution();
	cout << test->findShortestWay(input, ball, hole) << endl;
	return 0;
}
