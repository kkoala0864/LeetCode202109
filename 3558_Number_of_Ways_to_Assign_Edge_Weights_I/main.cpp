#include <Solution.h>

int main(void) {
	vector<vector<int>> edges = {{1,2},{2,3},{3,4}};
	Solution *test = new Solution();
	cout << test->assignEdgeWeights(edges) << endl;
	return 0;
}
