#include <Solution.h>

int main(void) {
	vector<vector<int>> edges = {{2,0},{3,1},{2,1}};
	int n = 4;
	Solution *test = new Solution();
	auto result = test->sumOfDistancesInTree(n, edges);
	for (auto &val : result) {
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
