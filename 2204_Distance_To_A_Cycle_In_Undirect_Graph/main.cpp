#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> graph = {{1, 2}, {2, 4}, {4, 3}, {3, 1}, {0, 1}, {5, 2}, {6, 5}};
	int n = 7;
	Solution *test = new Solution();
	auto result = test->distanceToCycle(n, graph);
	for (const auto &iter : result)
		cout << iter << " ";
	cout << endl;
	return 0;
}
