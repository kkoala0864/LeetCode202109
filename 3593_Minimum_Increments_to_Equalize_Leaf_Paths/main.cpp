#include <Solution.h>

int main(void) {
	int n = 3;
	vector<vector<int>> edges = {{0,1},{0,2}};
	vector<int> cost = {2, 1, 3};
	Solution *test = new Solution();
	cout << test->minIncrease(n, edges, cost) << endl;
	return 0;
}
