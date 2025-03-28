#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
	Graph *test = new Graph(4, input);
	cout << test->shortestPath(3, 2) << endl;
	cout << test->shortestPath(0, 3) << endl;
	test->addEdge({1, 3, 4});
	cout << test->shortestPath(0, 3) << endl;
	return 0;
}
