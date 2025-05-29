#include <Solution.h>

int main(void) {
	vector<vector<int>> edge1 = {{0,1},{0,2},{2,3},{2,4}};
	vector<vector<int>> edge2 = {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
	Solution *test = new Solution();
	auto result = test->maxTargetNodes(edge1, edge2);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
