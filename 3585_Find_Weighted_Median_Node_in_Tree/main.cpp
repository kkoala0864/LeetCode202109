#include <Solution.h>

int main(void) {
	vector<vector<int>> edges = {{0,1,2},{2,0,4}};
	vector<vector<int>> queries = {{2,0}};
	int n = 3;
	Solution *test = new Solution();
	auto result = test->findMedian(n, edges, queries);
	for (const auto& e : result) {
		cout << e << " ";
	}
	cout << endl;
	return 0;
}
