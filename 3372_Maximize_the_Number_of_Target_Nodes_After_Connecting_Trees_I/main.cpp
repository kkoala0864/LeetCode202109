#include <Solution.h>

int main(void) {
	vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4}};
	vector<vector<int>> edges2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
	int k = 2;
	Solution *test = new Solution();
	auto result = test->maxTargetNodes(edges1, edges2, k);
	for (const auto& r : result) cout << r << " ";
	cout << endl;
	return 0;
}
