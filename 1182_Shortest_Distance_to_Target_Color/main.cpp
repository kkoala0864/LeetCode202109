#include <Solution.h>

int main(void) {
	vector<int> colors = {1,1,2,1,3,2,2,3,3};
	vector<vector<int>> queries = {{1,3},{2,2},{6,1}};
	Solution *test = new Solution();
	auto result = test->shortestDistanceColor(colors, queries);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
