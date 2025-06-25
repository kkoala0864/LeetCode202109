#include <Solution.h>

int main(void) {
	int n = 8;
	vector<vector<int>> edges = {{1,2,6},{1,3,4},{2,4,6},{2,5,3},{3,6,6},{3,0,8},{7,0,2}};
	vector<vector<int>> queries = {{4,6},{0,4},{6,5},{7,4}};
	Solution *test = new Solution();
	auto result = test->minOperationsQueries(n, edges, queries);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
