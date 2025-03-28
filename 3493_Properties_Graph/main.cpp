#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> graph = {{1, 2}, {1, 1}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
	int k = 1;
	Solution *test = new Solution();
	cout << test->numberOfComponents(graph, k) << endl;
	return 0;
}
