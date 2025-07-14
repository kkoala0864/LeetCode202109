#include <Solution.h>

int main(void) {
	vector<vector<int>> input = {{2,1},{3,1},{4,2},{1,4}};
	Solution *test = new Solution();
	auto result = test->findRedundantDirectedConnection(input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
