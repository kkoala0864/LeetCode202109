#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> query = {{0, 6}, {4, 12}};
	int n = 14;
	Solution *test = new Solution();
	auto result = test->shortestDistanceAfterQueries(n, query);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
