#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
	vector<int> start = {0, 4};
	vector<int> end = {3, 2};
	Solution* test = new Solution();
	cout << test->hasPath(maze, start, end) << endl;
	return 0;
}

