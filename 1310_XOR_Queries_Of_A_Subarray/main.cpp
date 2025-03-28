#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {1, 3, 4, 8};
	vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
	Solution *test = new Solution();
	auto result = test->xorQueries(input, queries);
	for (const auto &v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
