#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> queries = {{1, 2}, {3, 4}, {2, 3}, {-3, 0}};
	int k = 2;
	Solution *test = new Solution();
	auto result = test->resultsArray(queries, k);
	for (const auto &v : result)
		cout << v << " ";
	cout << endl;
	return 0;
}
