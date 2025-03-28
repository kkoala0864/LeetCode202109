#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 4}, {4, 5}};
	Solution *test = new Solution();
	cout << test->treeDiameter(edges) << endl;
	return 0;
}
