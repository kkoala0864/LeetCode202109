#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
	vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
	int m = 4;
	int n = 6;
	Solution *test = new Solution();
	cout << test->countUnguarded(m, n, guards, walls) << endl;
	return 0;
}
