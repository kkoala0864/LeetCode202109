#include <Solution.h>

int main(void) {
	int c = 5;
	vector<vector<int>> input = {{1,2},{2,3},{3,4},{4,5}};
	vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};
	Solution *test = new Solution();
	auto result = test->processQueries(c, input, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
