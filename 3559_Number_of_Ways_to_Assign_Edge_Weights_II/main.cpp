#include <Solution.h>

int main(void) {
	vector<vector<int>> edges = {{1,2},{1,3},{3,4},{3,5}};
	vector<vector<int>> queries = {{1,4},{3,4},{2,5}};
	Solution *test = new Solution();
	auto result = test->assignEdgeWeights(edges, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
