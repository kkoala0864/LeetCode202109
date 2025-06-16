#include <Solution.h>

int main(void) {
	vector<vector<int>> edges = {{0,1},{1,2},{1,3},{4,2}};
	vector<vector<int>> guesses = {{1,3},{0,1},{1,0},{2,4}};
	int k = 3;
	Solution *test = new Solution();
	cout << test->rootCount(edges, guesses, k) << endl;
	return 0;
}
