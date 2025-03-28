#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> graph = {{4, 2}, {3, 4}, {0, 3}, {1, 0}, {2, 1}};
	string color = "rrrde";
	Solution *test = new Solution();
	cout << test->largestPathValue(color, graph) << endl;
	return 0;
}
