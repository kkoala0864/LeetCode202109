#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> commands = {4, -1, 3};
	vector<vector<int>> obstacles = {};
	Solution *test = new Solution();
	cout << test->robotSim(commands, obstacles) << endl;
	return 0;
}
