#include <Solution.h>

int main(void) {
	int n = 3;
	vector<vector<int>> edges = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
	vector<vector<int>> queries = {{0,1,2},{0,2,5}};
	Solution *test = new Solution();
	auto result = test->distanceLimitedPathsExist(n, edges, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
