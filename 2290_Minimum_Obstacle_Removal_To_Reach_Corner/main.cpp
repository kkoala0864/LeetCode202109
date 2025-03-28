#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
	Solution *test = new Solution();
	cout << test->minimumObstacles(input) << endl;
	cout << test->minimumObstacles2(input) << endl;
	cout << test->Dijkstra(input) << endl;
	return 0;
}
